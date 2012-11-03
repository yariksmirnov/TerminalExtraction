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
#include "UnAnimRenderObject.h"
#include "RenderSystem.h"
#include "Shader.h"
#include "Display.h"

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
    _shader = new Shader("ShaderBackground.vsh", "ShaderBackground.fsh");
    
  
       
    
  
}

void TEEngine::RunLoop(double delta) {
    _elapsedTime = delta;
    _fullTime += _elapsedTime;
    
    this->Update();
    this->Draw();
}

void TEEngine::Update() {
    
}

void TEEngine::Draw() {

    _renderSystem->Draw();
    
    
    glUseProgram(_shader->GetProgram());
    _shader->SetMatrixValue(UNIFORM_VIEW_MATRIX, _camera->view.m);
    _shader->SetMatrixValue(UNIFORM_PROJECTION_MATRIX, _camera->projection.m);
    GLKMatrix4 m = GLKMatrix4Identity;
    _shader->SetMatrixValue(UNIFORM_MODEL_MATRIX, m.m);
    _cube->GetRenderAspect()->Render(0, nullptr);
    glUseProgram(0);
    _renderSystem->EndFrame();
}

float TEEngine::ElapsedTime() {
    return _elapsedTime;
}

TEEngine::~TEEngine() {
    delete _renderSystem;
}