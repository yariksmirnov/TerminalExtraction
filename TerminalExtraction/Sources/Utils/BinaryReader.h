//
//  BinaryReader.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/19/12.
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
    
};

#endif /* defined(__TerminalExtraction__BinaryReader__) */
