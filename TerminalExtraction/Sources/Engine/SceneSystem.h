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
    
    UContainer<PivotObject>          _shadowObjects;
    UContainer<PivotObject>          _visibleObjects;
    UContainer<PivotObject>          _objects;
    
public:
   
    SceneSystem();
    ~SceneSystem();
    
    void SwapObjects(const shared_ptr<PivotObject> anObject, const shared_ptr<PivotObject> newObject, bool recaclulate);
    void Clear();
    shared_ptr<PivotObject> GetObject(unsigned int objId);
    void AddObject(const shared_ptr<PivotObject> newObject, bool needUpdate);
    void DeleteObjects(UContainer<PivotObject> *objects);
    void RemoveObject(const shared_ptr<PivotObject> object);
    void AddObject(UContainer<PivotObject> *newObjects);
    void UpdateScene();
    void AfterUpdate();
    void CalculateVisbleObject();
    
    void BeginFrame();
    void EndFrame();
    void Frame(double time);
};


#endif /* defined(__TerminalExtraction__SceneSystem__) */
