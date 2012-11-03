//
//  ios_fileManager.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#ifndef __TerminalExtraction__ios_fileManager__
#define __TerminalExtraction__ios_fileManager__

#include <iostream>

#include "FileManger.h"

class iosFileManager : public FileManager {
    
public:
    
    virtual string GetContent(string filename);
    
};

#endif /* defined(__TerminalExtraction__ios_fileManager__) */
