//
//  Display.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#ifndef __TerminalExtraction__Display__
#define __TerminalExtraction__Display__
#include "GlobalConstants.h"

#include <iostream>
#include GLES2

class Display {
    static Display * _current;
    
public:
    static Display * currentDisplay();
    
    virtual void  InitGLSurface(unsigned int depthFormat, unsigned int pixelFormat);
    
    virtual GLfloat GetDisplayHeight();
    virtual GLfloat GetDisplayWidth();
    
    virtual void SwapBuffers();

};

#endif /* defined(__TerminalExtraction__Display__) */
