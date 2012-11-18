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
#include "FileManger.h"
#include "Utils.h"

#include "cocos2d.h"

#include "LevelObject.h"
#include "Camera.h"
#include "UnAnimRenderObject.h"
#include "RenderSystem.h"
#include "Shader.h"
#include "Display.h"
#include "EngineMesh.h"
#include "Geometry.h"
#include "SceneSystem.h"
#include "ContentProvider.h"

using namespace cocos2d;
using namespace Kompex;

TEEngine globalEngine;
TEEngine * engine = &globalEngine;

TEEngine::TEEngine() {
    _renderSystem = new RenderSystem();
}

void TEEngine::Init() {
    
    SysInit();
    
    _contentProvider = new ContentProvider();
    _renderSystem->Init();
    _renderSystem->InitOpenGL();
    
    
    GRect2D _screenRect = GRect2DMake(0, 0, _renderSystem->GetDisplay()->GetDisplayWidth(), _renderSystem->GetDisplay()->GetDisplayHeight());
    _camera = new Camera(GLKVector3Make(3, 1.5, 3), GLKVector3Make(0, 0, 0), _screenRect);
    
    
    _cube = shared_ptr<LevelObject>(LevelObject::CreateCube());
    
    
    _shader = new Shader("ShaderBackground.vsh", "ShaderBackground.fsh");
    _shader1 = new Shader("ShaderPostQuad.vsh", "ShaderPostQuad.fsh");
    
    _director = CCDirector::sharedDirector();
    _director->setOpenGLView((CCEGLView *)(_renderSystem->GetDisplay()));
    
    _renderSystem->GetDisplay()->setDesignResolutionSize(_renderSystem->GetDisplay()->GetDisplayWidth(), _renderSystem->GetDisplay()->GetDisplayHeight(), kResolutionNoBorder);
    _director->setContentScaleFactor(2.0f);
    
    
  //  _director->startAnimation();
    
    _scene = new SceneSystem();
    
    _scene->AddObject(_cube, true);
    _scene->GetInterfaceManager()->Prepare();
    _director->pushScene(_scene->GetInterfaceManager()->GetGUISession());
    
    _director->setDisplayStats(true);
    
    
    _cube->SetGlobalPosition(GLKMatrix4MakeTranslation(-1, 5, 0), nullptr, nullptr, true);
}

void TEEngine::AddObject(const shared_ptr<PivotObject>& object, const shared_ptr<PivotObject>& parentObject)
{
//    LevelObject loNew = __object as LevelObject;
//    if (loNew == null)
//        return;
//    
//    if (loNew.renderaspect.isanimated)
//    {
//        Render.AnimRenderObject ro = loNew.renderaspect as Render.AnimRenderObject;
//        AnimationManager.AnimationManager.Manager.AddAnimationUserEnd(ro);
//    }
//    
//    gameScene.AddObject(__object);
//    
//    if (__parentObject != null)
//    {
//        __object.behaviourmodel.SetParentObject(__parentObject);
//        gameScene._objects.AddRule(__parentObject, __object);
//    }
    RenderObject* ro = object->GetRenderAspect();
    ro = ro;
    //is anim
    
    _scene->AddObject(object, true);
    if(parentObject)
    {
        //lalala
    }
    
}

Shader * TEEngine::GetShader() {
    return _shader;
}

void TEEngine::RunLoop(double delta) {
    _elapsedTime = delta;
    _fullTime += _elapsedTime;
    
    glClearColor(_color, _color, _color, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    this->Update();
    this->Draw();
    
    this->DrawInterface();
    this->EndFrame();
}

void TEEngine::switchLight() {
    float abs = _color - 0.6;
    if(abs < 0)
        abs = -abs;
    
    if (abs<0.1 ) {
        _color = 0;
    } else {
        _color = 0.6;
    }
}

void TEEngine::EndFrame() {
    _renderSystem->EndFrame();
}

void TEEngine::DrawInterface() {
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
    _director->mainLoop();
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
}

void TEEngine::Update() {
    
    _scene->BeginFrame();
    
    
    _scene->PhysicFrame(_elapsedTime);
    _scene->Frame(_elapsedTime);
    
    
    //End updating world objects
    _scene->EndFrame();
    _scene->UpdateScene();
}

void TEEngine::Draw() {

    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    glDisable(GL_CULL_FACE);
    
    
    glUseProgram(_shader->GetProgram());
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
    GLKMatrix4 m1 = _cube->GetTransformMatrix();
    //printf("x: %f y: %f z: %f\n", m1.m30, m1.m31, m1.m32);
    _shader->SetMatrixValue(UNIFORM_MODEL_MATRIX, m1.m);
    {
        GLenum err = glGetError();
        if (err != GL_NO_ERROR)
            printf(" glError: 0x%04X", err);
    }
    
    _cube->GetRenderAspect()->Render(0, _cube->GetMaterial());
    {
        GLenum err = glGetError();
        if (err != GL_NO_ERROR)
            printf(" glError: 0x%04X", err);
    }
}

float TEEngine::ElapsedTime() {
    return _elapsedTime;
}

void TEEngine::applicationDidEnterBackground() {
    
}

bool TEEngine::applicationDidFinishLaunching() {
    return true;
}

void TEEngine::applicationWillEnterForeground() {
    
}

TEEngine::~TEEngine() {
    delete _contentProvider;
    delete _renderSystem;
    delete _shader;
    delete _shader1;
}