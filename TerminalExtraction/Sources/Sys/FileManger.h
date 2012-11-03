//
//  FileManger.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#ifndef __TerminalExtraction__FileManger__
#define __TerminalExtraction__FileManger__

#include <iostream>

using namespace std;

class FileManager {
    
public:
    
    static FileManager *CreateManager();
    
    virtual string GetContent(string filename);
};

#endif /* defined(__TerminalExtraction__FileManger__) */
