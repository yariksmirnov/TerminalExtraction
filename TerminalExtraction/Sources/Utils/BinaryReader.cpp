//
//  BinaryReader.cpp
//  TerminalExtraction
//
//  Created by Mister Pattern on 11/19/12.
//
//

#include "BinaryReader.h"
#include "FileManger.h"


BinaryReader::BinaryReader(std::string filename):_position(0):_filesize(0) {
    FileManager *fm = FileManager::CreateManager();
    std::string path = fm->GetFilePath(filename);
    _file = fopen(path.c_str(), "rb");
    
    delete fm;
    
    fseek(_file, 0, SEEK_END);
    _filsize = ftell(_file);
    fseek(_file, 0, SEEK_SET);
    _currentBuffer = malloc(_filesize);
}

BinaryReader::BinaryReader(const void *buffer, unsigned int length)
:_position(0)
:_filesize(0)
:_file(NULL)
{
    _internalBuffer(const_cast<void *>(buffer));
    _filesize(length);
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
        _currentBuffer = _internalBuffer + _position;
    }
}


int BinaryReader::ReadInt() {
    if (_file) {
        int retVal;
        _currentBuffer = &retVal;
        fread(_currentBuffer), sizeof(int), 1, _file);
    }
    return (* _currentBuffer);
}

float BinaryReader::ReadSingle() {
    if (_file) {
        float retVal;
        _currentBuffer = &retVal;
        fread(_currentBuffer, sizeof(float), 1, _file);
    }
    return (* _currentBuffer);
}

void BinaryReader::ReadBuffer(int length, const void *buf) {
    if (_file) {
        fread(buf, length, 1, _file);
        return;
    }
    memcpy(buf, _currentBuffer, length);
    return;
}

string BinaryReader::ReadString() {
    int length = ReadInt() + 1;
    char *buff = new char[length];
    ReadBuffer(length, buff);
    string str = string(buff);
    delete [] buff;
    return str;
}

BinaryReader::~BinaryReader() {
    if (_file) {
        fclose(_file);
    }
    free(_currentBuffer);
}


