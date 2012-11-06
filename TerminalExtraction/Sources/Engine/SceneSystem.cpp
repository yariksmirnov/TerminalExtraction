//
//  SceneSystem.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/5/12.
//
//

#include "SceneSystem.h"

using namespace std;

SceneSystem::SceneSystem() {
    _objects = new UContainer(100);
    _visibleObjects = new UContainer(100);
    _shadowObjects = new UContainer(100);
    
}

SceneSystem::~SceneSystem() {
    delete _visibleObjects;
    delete _shadowObjects;
    delete _objects;
}

