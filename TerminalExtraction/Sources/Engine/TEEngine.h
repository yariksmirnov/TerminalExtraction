//
//  TEEngine.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/17/12.
//
//

#ifndef __TerminalExtraction__TEEngine__
#define __TerminalExtraction__TEEngine__

#include <iostream>
//#include "Geometry.h"

#include "cocos2d.h"

using namespace cocos2d;


class RenderSystem;
class Shader;

class LevelObject;
class Camera;
class EngineMesh;
class SceneSystem;

class TEEngine : private CCApplication {
    
    RenderSystem        *_renderSystem;
    float                _elapsedTime;
    float                _fullTime;
    
    std::shared_ptr<LevelObject>         _cube;
    //LevelObject         *_plane;
    
    
    Camera              *_camera;
    
    SceneSystem         *_scene;
    
    Shader              *_shader;
    Shader              *_shader1;
    
    GLfloat             _color;
    
public:
    
    //GRect2D _screenRect;

    CCDirector          *_director;
    
    TEEngine();
    ~TEEngine();
    
    void Init();
    void EngineMain();
    
    void RunLoop(double delta);
    
    float ElapsedTime();
    
    void Update();
    void Draw();
    void DrawInterface();
    void EndFrame();
    
    
    Shader * GetShader();

    
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();
    
    //test
    
    void switchLight();
};


extern TEEngine *  engine;

#endif /* defined(__TerminalExtraction__TEEngine__) */
