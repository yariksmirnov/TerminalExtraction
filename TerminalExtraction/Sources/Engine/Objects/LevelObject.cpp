//
//  LevelObject.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "LevelObject.h"
#include "EngineMesh.h"
#include "PhysicObjectBehaviourModel.h"
#include "StaticObjectBehaviorModel.h"
#include "UnAnimRenderObject.h"
#include "TextureMaterial.h"
#include "btRigidBody.h"
#include "btBoxShape.h"
#include "btDefaultMotionState.h"

LevelObject::LevelObject(RenderObject *renderObject, ObjectBehaviourModel *behaviorModel, Material *material):PivotObject(behaviorModel) {
    _renderAspect = renderObject;
    _material = material;
}

LevelObject * LevelObject::CreateCube() {
    const EngineMesh * mesh = EngineMesh::CreateCube();
    Material *material = new TextureMaterial("woodbox.jpg");
    
    btCollisionShape *shape = new btBoxShape(btVector3(0.5, 0.5, 0.5));
	btVector3 fallInertia(0,0,0);
    shape->calculateLocalInertia(10, fallInertia);
    
    
    btDefaultMotionState *motionState = new btDefaultMotionState();
    btTransform t;
    t.setRotation(btQuaternion(btVector3(1, 0, 0), 0));
    motionState->setWorldTransform(t);
    
    btRigidBody::btRigidBodyConstructionInfo info(10, motionState, shape, fallInertia);
    btRigidBody *body = new btRigidBody(info);
    body->setCollisionFlags(0);
    body->setRestitution(0.01);
    ObjectBehaviourModel *obmm = new PhysicObjectBehaviuorModel(body);
    
    RenderObject *renderObject = new UnAnimRenderObject(mesh);
    
    
    LevelObject * result = new LevelObject(renderObject, obmm, material);
    return result;
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

void LevelObject::Frame(double time)
{
    _objectBehaviourModel->Frame(time);
   // _renderAspect->SetPosition(_cu);
}

Material * LevelObject::GetMaterial()
{
    return _material;
}

LevelObject::~LevelObject() {
    delete _renderAspect;
    delete _material;
}
