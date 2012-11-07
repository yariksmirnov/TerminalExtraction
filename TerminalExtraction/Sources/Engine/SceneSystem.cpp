//
//  SceneSystem.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/5/12.
//
//

#include "SceneSystem.h"
#include "PivotObject.h"

using namespace std;

SceneSystem::SceneSystem() {
    _objects = new UContainer<PivotObject>(100);
    _visibleObjects = new UContainer<PivotObject>(100);
    _shadowObjects = new UContainer<PivotObject>(100);
    
}

SceneSystem::~SceneSystem() {
    delete _visibleObjects;
    delete _shadowObjects;
    delete _objects;
}

