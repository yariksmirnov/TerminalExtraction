//
//  SceneSystem.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/5/12.
//
//

#ifndef __TerminalExtraction__SceneSystem__
#define __TerminalExtraction__SceneSystem__

#include <iostream>
#include "Utils.h"

using namespace Utils;

class PivotObject;

class SceneSystem {
    
    UContainer          *_shadowObjects;
    UContainer          *_visibleObjects;
    UContainer          *_objects;
    
public:
   
    SceneSystem();
    ~SceneSystem();
    
    void SwapObjects(PivotObject *anObject, PivotObject *newObject, bool recaclulate);
    void Clear();
    PivotObject *GetObject(unsigned int objId);
    void AddObject(PivotObject *newObject, bool needUpdate);
    void DeleteObjects(UContainer *objects);
    void RemoveObject(PivotObject *object);
    void AddObject(UContainer *newObjects);
    void UpdateScene();
    void AfterScene();
    void CalculateVisbleObject();
    
    void BeginFrame();
    void EndFrame();
    void Frame(double time);
};


#endif /* defined(__TerminalExtraction__SceneSystem__) */
