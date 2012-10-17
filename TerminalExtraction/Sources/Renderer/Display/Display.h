//
//  Display.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#ifndef __TerminalExtraction__Display__
#define __TerminalExtraction__Display__

#include <iostream>


class Display {
    static Display * _current;
    
public:
    static Display * currentDisplay();
    
    virtual void InitGLSurface();
};

#endif /* defined(__TerminalExtraction__Display__) */
