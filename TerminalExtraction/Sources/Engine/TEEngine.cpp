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
#include "LevelObject.h"
#include "Camera.h"

TEEngine globalEngine;
TEEngine * engine = &globalEngine;

TEEngine::TEEngine() {
    _renderSystem = new RenderSystem();
}

void TEEngine::Init() {
    _renderSystem->Init();
    _renderSystem->InitOpenGL();
    
    
    GRect2D screen = GRect2DMake(0, 0, _renderSystem->GetDisplay()->GetDisplayWidth(), _renderSystem->GetDisplay()->GetDisplayHeight());
    _camera = new Camera(GLKVector3Make(5, 5, 5), GLKVector3Make(0, 0, 0), screen);
    
    _cube = LevelObject::CreateCube();
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
    
    _cube->BeginFrame();
    _cube->EndFrame();
}

float TEEngine::ElapsedTime() {
    return _elapsedTime;
}

TEEngine::~TEEngine() {
    delete _renderSystem;
}