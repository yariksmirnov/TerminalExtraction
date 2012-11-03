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

LevelObject::LevelObject(RenderObject *renderObject, ObjectBehaviourModel *behaviorModel, Material *material):PivotObject(behaviorModel) {
    _renderAspect = renderObject;
    material = material;
}

LevelObject * LevelObject::CreateCube() {
    const EngineMesh * mesh = EngineMesh::CreateCube();
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
    return material;
}
