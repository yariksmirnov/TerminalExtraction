//
//  BinaryReader.cpp
//  TerminalExtraction
//
//  Created by Mister Pattern on 11/19/12.
//
//

#include "BinaryReader.h"
#include "FileManger.h"


BinaryReader::BinaryReader(std::string filename) {
    FileManager *fm = FileManager::CreateManager();
    std::string path = fm->GetFilePath(filename);
    
    _file = std::ifstream(filename.c_str() , ios_base::in | ios_base::binary );
}

BinaryReader::BinaryReader(const void* buffer) {
   
    
   // _file = std::istream(filename.c_str() , ios_base::in | ios_base::binary );
}

long BinaryReader::GetPosition() {
    return _file.tellg();
}

void BinaryReader::SetPosition(long position) {
    _file.seekg(position);
}


int BinaryReader::ReadInt() {
    int i;
    _file >> i;
    return i;
}

float BinaryReader::ReadSingle() {
    float i;
    _file >> i;
    return i;
}

void BinaryReader::ReadBuffer(int length, const void *buf) {
    _file.read(const_cast<char *>(static_cast<const char *>(buf)), length);
}

string BinaryReader::ReadString() {
    int length = ReadInt() + 1;
    char *buff = new char[length];
    ReadBuffer(length, buff);
    string str = string(buff);
    delete [] buff;
    return str;
}



