//
//  PackObjectInterface.h
//  TerminalExtraction
//
//  Created by Anton Katekov on 22.11.12.
//
//

#ifndef __TerminalExtraction__PackObjectInterface__
#define __TerminalExtraction__PackObjectInterface__

#include <iostream>

class PackObjectInterface {
public:
    virtual void Dispose() = 0;
    virtual void LoadFromBuffer(char *buffer);
};

#endif /* defined(__TerminalExtraction__PackObjectInterface__) */
