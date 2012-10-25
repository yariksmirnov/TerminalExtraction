//
//  RenderSystem.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#include "RenderSystem.h"


RenderSystem::RenderSystem() {
    _deviceDisplay = Display::currentDisplay();
}

void RenderSystem::Init() {
    _deviceDisplay->InitGLSurface(GL_RGB565, GL_RGB);
}

void RenderSystem::InitOpenGL() {
    
}

