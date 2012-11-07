//
//  SceneSystem.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/5/12.
//
//

#include "SceneSystem.h"
#include "PivotObject.h"
#include "RenderObject.h"
#include "EditorData.h"

using namespace std;

SceneSystem::SceneSystem() {
    _objects = UContainer<PivotObject>(100);
    _visibleObjects = UContainer<PivotObject>(100);
    _shadowObjects = UContainer<PivotObject>(100);
}

SceneSystem::~SceneSystem() {
}



void SceneSystem::AddObject(shared_ptr<PivotObject> newObject, bool needUpdate) {
    if (needUpdate) {
        newObject->BeginFrame();
        newObject->Frame(0);
        newObject->EndFrame();
        newObject->Update();
    }
    newObject->AfterUpdate();
    //newObject.behaviourmodel.Enable();
    _objects.addObject(newObject);
    //_sceneGraph.AddObject(newObject);
}

void SceneSystem::UpdateScene() {
    for (int i = 0; i < _objects.GetCount(); i++) {
        _objects.objectAtIndex(i)->Update();
    }
    //_sceneGraph.NewFrame();
    _visibleObjects.clear();
    _shadowObjects.clear();
}

void SceneSystem::AfterUpdate() {
    for (int i = 0; i < _objects.GetCount(); i++) {
        _objects.objectAtIndex(i)->Update();
    }
}

void SceneSystem::CalculateVisbleObject() {
    //_sceneGraph.calculateVisibleObjects(CameraControllers.CameraManager.Camera.cameraFrustum, _visibleObjects);
    //_sceneGraph.calculateShadowVisibleObjects(GameEngine.Instance.GraphicPipeleine.frustumForShadow, _shadowObjects);
    
    _visibleObjects.AddObjects(_objects);
}

void SceneSystem::BeginFrame() {
    for (int i = 0; i < _objects.GetCount(); i++) {
        _objects.objectAtIndex(i)->BeginFrame();
    }
}

void SceneSystem::Frame(double time) {
    for (int i = 0; i < _objects.GetCount(); i++) {
        _objects.objectAtIndex(i)->Frame(time);
    }
}

void SceneSystem::EndFrame() {
    for (int i = 0; i < _objects.GetCount(); i++) {
        _objects.objectAtIndex(i)->EndFrame();
    }
}

void SceneSystem::Clear() {
    _visibleObjects.clear();
    _shadowObjects.clear();
    _objects.clear();
    
    IdGenerator::DefaultGenerator()->Reset();
}

shared_ptr<PivotObject> SceneSystem::GetObject(unsigned int objId) {
    for (int i = 0; i < _objects.GetCount(); i++) {
        if (_objects.objectAtIndex(i)->GetEditorAspect()->objectId() == objId) {
            return _objects.objectAtIndex(i);
        }
    }
    return nullptr;
}

void SceneSystem::DeleteObjects(UContainer<PivotObject> *objects) {
    
}

void SceneSystem::RemoveObject(shared_ptr<PivotObject> object) {
    _objects.removeObject(object);
    //_sceneGraph.RemoveObject(deletingobjects);
    //deletingobjects.behaviourmodel.Disable();
    if (_objects.GetCount() == 0)
        IdGenerator::DefaultGenerator()->Reset();
}

