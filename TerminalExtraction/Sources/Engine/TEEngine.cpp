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
#include "EngineMesh.h"

TEEngine globalEngine;
TEEngine * engine = &globalEngine;

TEEngine::TEEngine() {
    _renderSystem = new RenderSystem();
}

void TEEngine::Init() {
    _renderSystem->Init();
    _renderSystem->InitOpenGL();
    
    
    GRect2D screen = GRect2DMake(0, 0, _renderSystem->GetDisplay()->GetDisplayWidth(), _renderSystem->GetDisplay()->GetDisplayHeight());
    _camera = new Camera(GLKVector3Make(2, 2, 2), GLKVector3Make(0, 0, 0), screen);
    
    _cube = LevelObject::CreateCube();
    _plane = LevelObject::CreatePlane();
    
    _shader = new Shader("ShaderBackground.vsh", "ShaderBackground.fsh");
    _shader1 = new Shader("ShaderPostQuad.vsh", "ShaderPostQuad.fsh");
    
    
       
    
  
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

    
    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);
    
    glUseProgram(_shader1->GetProgram());
    _shader->SetMatrixValue(UNIFORM_VIEW_MATRIX, _camera->view.m);
    {
        GLenum err = glGetError();
        if (err != GL_NO_ERROR)
            printf(" glError: 0x%04X", err);
    }
    
    _shader->SetMatrixValue(UNIFORM_PROJECTION_MATRIX, _camera->projection.m);
    {
        GLenum err = glGetError();
        if (err != GL_NO_ERROR)
            printf(" glError: 0x%04X", err);
    }
    
    GLKMatrix4 m = GLKMatrix4Identity;
    _shader->SetMatrixValue(UNIFORM_MODEL_MATRIX, m.m);
    {
        GLenum err = glGetError();
        if (err != GL_NO_ERROR)
            printf(" glError: 0x%04X", err);
    }
    
    _cube->GetRenderAspect()->Render(0, nullptr);
    {
        GLenum err = glGetError();
        if (err != GL_NO_ERROR)
            printf(" glError: 0x%04X", err);
    }
    glUseProgram(0);
    
    
    
    _renderSystem->EndFrame();
}

float TEEngine::ElapsedTime() {
    return _elapsedTime;
}

TEEngine::~TEEngine() {
    delete _renderSystem;
}