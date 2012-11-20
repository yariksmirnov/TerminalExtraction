//
//  BinaryReader.h
//  TerminalExtraction
//
//  Created by Mister Pattern on 11/19/12.
//
//

#ifndef __TerminalExtraction__BinaryReader__
#define __TerminalExtraction__BinaryReader__

#include <iostream>
#include <fstream>
#include <iosfwd>

using namespace std;

class BinaryReader {
    
    ifstream            _file;
    
public:
    
    BinaryReader(std::string filename);
    BinaryReader(const void* buffer);
    
    long GetPosition();
    int ReadInt();
    float ReadSingle();
    string ReadString();
	void ReadBuffer(int length, const void *buf);
    void SetPosition(long position);
};

#endif /* defined(__TerminalExtraction__BinaryReader__) */
