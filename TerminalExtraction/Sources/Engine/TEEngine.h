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

class RenderSystem;
class Shader;


class LevelObject;
class Camera;
class EngineMesh;

class TEEngine {
    
    RenderSystem        *_renderSystem;
    float                _elapsedTime;
    float                _fullTime;
    
    LevelObject         *_cube;
    LevelObject         *_plane;
    
    
    Camera              *_camera;
    
    Shader              *_shader;
    Shader              *_shader1;
    
public:
    
    //GRect2D _screenRect;
    
    TEEngine();
    ~TEEngine();
    
    void Init();
    void EngineMain();
    
    void RunLoop(double delta);
    
    float ElapsedTime();
    
    void Update();
    void Draw();
    
    
    Shader * GetShader();

};


extern TEEngine *  engine;

#endif /* defined(__TerminalExtraction__TEEngine__) */
