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
    
public:
    TEEngine();
    ~TEEngine();
    
    void Init();
    void EngineMain();
};


extern TEEngine *  engine;

#endif /* defined(__TerminalExtraction__TEEngine__) */
