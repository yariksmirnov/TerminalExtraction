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
protected:
    bool _disposed;
public:
    virtual void Dispose();
    virtual void LoadFromBuffer(char *buffer, unsigned int bufferLength);
};

#endif /* defined(__TerminalExtraction__PackObjectInterface__) */
