//
//  TEEngine.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/17/12.
//
//

#include "TEEngine.h"



TEEngine globalEngine;
TEEngine * engine = &globalEngine;

TEEngine::TEEngine() {
    _renderSystem = new RenderSystem();
}

void TEEngine::Init() {
    
    _renderSystem->Init();
    
}

void TEEngine::EngineMain() {
    
    _renderSystem->InitOpenGL();
    
}

TEEngine::~TEEngine() {
    delete _renderSystem;
}