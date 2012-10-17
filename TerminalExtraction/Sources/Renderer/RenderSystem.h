//
//  RenderSystem.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#ifndef __TerminalExtraction__RenderSystem__
#define __TerminalExtraction__RenderSystem__

#include <iostream>
#include "Display.h"

class RenderSystem {
    Display     *_deviceDisplay;
public:
    RenderSystem();
    
    void Init();
    void InitOpenGL();
};

#endif /* defined(__TerminalExtraction__RenderSystem__) */
