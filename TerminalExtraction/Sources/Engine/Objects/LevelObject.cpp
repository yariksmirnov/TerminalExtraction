//
//  LevelObject.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "LevelObject.h"
#include "EngineMesh.h"
#include "StaticObjectBehaviorModel.h"
#include "UnAnimRenderObject.h"
#include "TextureMaterial.h"

LevelObject::LevelObject(RenderObject *renderObject, ObjectBehaviourModel *behaviorModel, Material *material):PivotObject(behaviorModel) {
    _renderAspect = renderObject;
    _material = material;
}

LevelObject * LevelObject::CreateCube() {
    const EngineMesh * mesh = EngineMesh::CreateCube();
    Material *material = new TextureMaterial("woodbox.jpg");
    
    ObjectBehaviourModel *obmm = new StaticObjectBehaviourModel();
    
    RenderObject *renderObject = new UnAnimRenderObject(mesh);
    
    return new LevelObject(renderObject, obmm, material);
}

LevelObject * LevelObject::CreatePlane() {
    const EngineMesh * mesh = EngineMesh::CreateFullscreenQuad();
    Material *material = nullptr;
    
    ObjectBehaviourModel *obmm = new StaticObjectBehaviourModel();
    
    RenderObject *renderObject = new UnAnimRenderObject(mesh);
    
    return new LevelObject(renderObject, obmm, material);
}

RenderObject * LevelObject::GetRenderAspect()
{
    return _renderAspect;
}

Material * LevelObject::GetMaterial()
{
    return _material;
}

LevelObject::~LevelObject() {
    delete _renderAspect;
    delete _material;
}
