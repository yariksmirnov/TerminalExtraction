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
#include <istream>
#include <fstream>
#include <iosfwd>

class BinaryReader {
    
    FILE            *_file;
    void            *_currentBuffer;
    void            *_internalBuffer;
    
    unsigned int    _filesize;
    long            _position;
    
public:
    
    BinaryReader(std::string filename);
    BinaryReader(const void *buffer, unsigned int length);
    ~ BinaryReader();
    
    long GetPosition();
    int ReadInt();
    float ReadSingle();
    std::string ReadString();
	void ReadBuffer(int length, const void *buf);
    void SetPosition(long position);
    
	unsigned int GetLength() { return _filesize; };
};

#endif /* defined(__TerminalExtraction__BinaryReader__) */
