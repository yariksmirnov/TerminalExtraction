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
#include "RenderSystem.h"

class TEEngine {
    RenderSystem        *_renderSystem;
    float                _elapsedTime;
    float                _fullTime;
public:
    TEEngine();
    ~TEEngine();
    
    void Init();
    void EngineMain();
    
    void RunLoop(double delta);
    
    float ElapsedTime();
    
    void Update();
    void Draw();

};


extern TEEngine *  engine;

#endif /* defined(__TerminalExtraction__TEEngine__) */
