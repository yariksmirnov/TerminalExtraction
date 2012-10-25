//
//  TEEngine.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/17/12.
//
//

#include "TEEngine.h"
#include <time.h>


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
    
    StartRunLoop();
}

void TEEngine::StartRunLoop() {
    
    double t = 0.0;
    const double dt = 0.01;
    
    time_t currentTime = time(NULL);
    double accumulator = 0.0;
    
    while ( true ) {
        time_t newTime = time(NULL);
        double frameTime = newTime - currentTime;
        if ( frameTime > 0.25 )
            frameTime = 0.25;	  // note: max frame time to avoid spiral of death
        currentTime = newTime;
        
        accumulator += frameTime;
        
        while ( accumulator >= dt )
        {
            t += dt;
            accumulator -= dt;
        }
        
        //const double alpha = accumulator / dt;
        
        
        
    }
    
}

TEEngine::~TEEngine() {
    delete _renderSystem;
}