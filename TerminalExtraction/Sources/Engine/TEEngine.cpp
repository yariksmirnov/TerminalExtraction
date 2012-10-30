//
//  TEEngine.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/17/12.
//
//

#include "TEEngine.h"
#include <time.h>
#include <math.h>


TEEngine globalEngine;
TEEngine * engine = &globalEngine;

TEEngine::TEEngine() {
    _renderSystem = new RenderSystem();
}

void TEEngine::Init() {
    _renderSystem->Init();
    _renderSystem->InitOpenGL();
}

void TEEngine::RunLoop(double delta) {
    _elapsedTime = delta;
    _fullTime += _elapsedTime;
    
    this->Update();
    this->Draw();
}

void TEEngine::Update() {
    _renderSystem-> SetColor(sinf(_fullTime/20.0) / 2 + 0.5);
}

void TEEngine::Draw() {
    _renderSystem->Draw();
}

float TEEngine::ElapsedTime() {
    return _elapsedTime;
}

TEEngine::~TEEngine() {
    delete _renderSystem;
}