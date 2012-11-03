//
//  RenderSystem.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#include "RenderSystem.h"
#include "Display.h"

RenderSystem::RenderSystem() {
    _deviceDisplay = Display::currentDisplay();
}

void RenderSystem::Init() {
    _deviceDisplay->InitGLSurface(GL_DEPTH_COMPONENT24_OES, GL_RGBA8_OES);
}

void RenderSystem::InitOpenGL() {
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    _deviceDisplay->SwapBuffers();
}

void RenderSystem::SetColor(float color){
    _color = color;
}

void RenderSystem::Draw(){
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_BLEND);
    
}

void RenderSystem::EndFrame() {
    _deviceDisplay->SwapBuffers();
}

Display * RenderSystem::GetDisplay() {
    return _deviceDisplay;
}