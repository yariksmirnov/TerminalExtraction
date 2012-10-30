//
//  RenderSystem.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#ifndef __TerminalExtraction__RenderSystem__
#define __TerminalExtraction__RenderSystem__

#include "GlobalConstants.h"
#include <iostream>
#include "Display.h"

#include GLES2
#include Glext

class RenderSystem {
    Display             *_deviceDisplay;
    float _color;
public:
    RenderSystem();
    
    void Init();
    void InitOpenGL();
    
    void Draw();
    void SetColor(float color);
};

#endif /* defined(__TerminalExtraction__RenderSystem__) */
