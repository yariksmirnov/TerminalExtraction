//
//  LevelObject.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "LevelObject.h"
#include "EngineMesh.h"

LevelObject::LevelObject(RenderObject *renderObject, ObjectBehaviourModel *behaviorModel, Material *material):PivotObject(behaviorModel) {
    _renderAspect = renderObject;
    material = material;
}

LevelObject * LevelObject::CreateCude() {
    const EngineMesh * mesh = EngineMesh::CreateCube();
    Material *material;
}
