//
//  BinaryReader.cpp
//  TerminalExtraction
//
//  Created by Mister Pattern on 11/19/12.
//
//

#include "BinaryReader.h"
#include "FileManger.h"
#include <memory>


BinaryReader::BinaryReader(std::string filename):_position(0),_filesize(0) {
    FileManager *fm = FileManager::CreateManager();
    std::string path = fm->GetFilePath(filename);
    _file = fopen(path.c_str(), "rb");
    
    delete fm;
    
    fseek(_file, 0, SEEK_END);
    _filesize = ftell(_file);
    fseek(_file, 0, SEEK_SET);
    _currentBuffer = static_cast<char*>(malloc(_filesize));
}

BinaryReader::BinaryReader(char *buffer, unsigned int length)
:_position(0)
,_filesize(length)
,_file(NULL)
{
    _internalBuffer = const_cast<char *>(buffer);
}

long BinaryReader::GetPosition() {
    if (_file) {
        _position = ftell(_file);
    }
    return _position;
}

void BinaryReader::SetPosition(long position) {
    if (position <= _filesize) {
        _position = position;
    }
    if (_file) {
        fseek(_file, _position, SEEK_SET);
    } else {
        _currentBuffer = reinterpret_cast<char *>(_internalBuffer) + _position;
    }
}


int BinaryReader::ReadInt() {
    if (_file) {
        
        int retVal;
        fread(&retVal, sizeof(int), 1, _file);
        return retVal;
    }
    int retVal = (* (int*)_currentBuffer);
    _currentBuffer += sizeof(int);
    return retVal;
}

float BinaryReader::ReadSingle() {
    if (_file) {
        float retVal;
        fread(&retVal, sizeof(float), 1, _file);
    }
    float retVal = (* (float*)_currentBuffer);
    _currentBuffer += sizeof(float);
    return retVal;
}

char BinaryReader::ReadChar() {
    if (_file) {
        char retVal;
        fread(&retVal, sizeof(char), 1, _file);
    }
    char retVal = (* (char*)_currentBuffer);
    _currentBuffer += sizeof(char);
    return retVal;
}

void BinaryReader::ReadBuffer(int length, char *buf) {
    if (_file) {
        size_t readed = fread(buf, sizeof(char), length, _file);
        readed = readed;
        return;
    }
    memcpy(buf, _currentBuffer, length);
    _currentBuffer += length;
    return;
}

string BinaryReader::ReadString() {
    int pos = GetPosition();
    int length = ReadInt();
    char *data = (char*) malloc (sizeof(char)*length+1);
    fread (data,sizeof(char),length+1,_file);
    if (data[length] != '\0') {
        ReadChar();
        
        char *dataold = data;
        data = (char*) malloc (sizeof(char)*length+2);
        memcpy(data, dataold, length+1);
        data[length+1]='\0';
        free(dataold);
    }
    string str = string(data);
    pos = GetPosition();
    free(data);
    return str;
}

BinaryReader::~BinaryReader() {
    if (_file) {
        fclose(_file);
    }
    free(_currentBuffer);
}


