//
//  PEPack.h
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#ifndef __TerminalExtraction__PEPack__
#define __TerminalExtraction__PEPack__

#include <iostream>
#include <string>
#include <vector>
#include "PackContentHeader.h"

class BinaryReader;

class Pack {
    void ReadPack();
    
public:
    std::string _filename;
    std::vector<shared_ptr<PackContentHeader>> _objects;
    int _headersize;
    BinaryReader* _reader;
    shared_ptr<PackContentHeader> FindObject(string name);
    Pack(std::string filename);
    ~Pack();
    
    bool ReadObjectFromPack(char* buffer, string name);
    bool ReadObjectFromPack(char* buffer, shared_ptr<PackContentHeader> obkect);
};


#endif /* defined(__TerminalExtraction__PEPack__) */
