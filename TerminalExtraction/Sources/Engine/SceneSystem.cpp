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
#include "ObjectBehaviourModel.h"
#include "PhysicObjectBehaviourModel.h"
#include "btIDebugDraw.h"

using namespace std;

SceneSystem::SceneSystem() {
    _objects = new UContainer<PivotObject>(100);
    _visibleObjects = new UContainer<PivotObject>(100);
    _shadowObjects = new UContainer<PivotObject>(100);
    
    _userInterface = new UserInterface;
    
    btBroadphaseInterface* broadphase = new btDbvtBroadphase();
	btDefaultCollisionConfiguration* collisionConfiguration = new btDefaultCollisionConfiguration();
	btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfiguration);
	btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();
    
    _physicScene = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfiguration);
    _physicScene->setGravity(btVector3(0, -9.8, 0));
    
    
    btCollisionShape *groundShape = new btStaticPlaneShape(btVector3(0, 1, 0), -1);
    
    btTransform gt = btTransform();
    gt.setIdentity();
    gt.setOrigin(btVector3(0,-1,0));
	btDefaultMotionState *groundMotionState = new btDefaultMotionState(gt);
    
    
	btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0,groundMotionState,groundShape,btVector3(0,0,0));
	groundRigidBodyCI.m_restitution = 0.0;
	btRigidBody* groundRigidBody = new btRigidBody(groundRigidBodyCI);
    groundRigidBody->setRollingFriction(1);
    groundRigidBody->setCollisionFlags(btCollisionObject::CF_STATIC_OBJECT);
	_physicScene->addRigidBody(groundRigidBody);
    //_physicScene->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_MAX_DEBUG_DRAW_MODE);
}

SceneSystem::~SceneSystem() {
    delete _objects;
    delete _visibleObjects;
    delete _shadowObjects;
    delete _userInterface;
}

void SceneSystem::AddObject(const shared_ptr<PivotObject> newObject, bool needUpdate) {
    PhysicObjectBehaviuorModel* m = dynamic_cast<PhysicObjectBehaviuorModel *>(newObject->GetBehavoiurModel());
    if(m)
    {
        btRigidBody* body = m->GetRigidBody();
        body->activate(true);
        body->setActivationState(DISABLE_DEACTIVATION);
		body->setLinearVelocity(btVector3(1,1,1));
        _physicScene->addRigidBody(body);
    }
    if (needUpdate) {
        newObject->BeginFrame();
        newObject->Frame(0);
        newObject->EndFrame();
        newObject->Update();
    }
    newObject->AfterUpdate();
    //newObject->_objectBehaviourModel->Enable();
    _objects->addObject(newObject);
    
    //_sceneGraph.AddObject(newObject);
}

void SceneSystem::UpdateScene() {
    for (int i = 0; i < _objects->GetCount(); i++) {
        shared_ptr<PivotObject> obj = _objects->objectAtIndex(i);
        obj->Update();
    }
    //_sceneGraph.NewFrame();
    _visibleObjects->clear();
    _shadowObjects->clear();
}

void SceneSystem::AfterUpdate() {
    for (int i = 0; i < _objects->GetCount(); i++) {
        _objects->objectAtIndex(i)->Update();
    }
}

void SceneSystem::CalculateVisbleObject() {
    //_sceneGraph.calculateVisibleObjects(CameraControllers.CameraManager.Camera.cameraFrustum, _visibleObjects);
    //_sceneGraph.calculateShadowVisibleObjects(GameEngine.Instance.GraphicPipeleine.frustumForShadow, _shadowObjects);
    
    _visibleObjects->AddObjects(_objects);
}

UserInterface * SceneSystem::GetInterfaceManager() {
    return _userInterface;
}

void SceneSystem::BeginFrame() {
    for (int i = 0; i < _objects->GetCount(); i++) {
        shared_ptr<PivotObject> obj = _objects->objectAtIndex(i);
        obj->BeginFrame();
    }
}

void SceneSystem::Frame(double time) {
    for (int i = 0; i < _objects->GetCount(); i++) {
        _objects->objectAtIndex(i)->Frame(time);
    }
   // _physicScene->debugDrawWorld();
}

void SceneSystem::PhysicFrame(double time)
{
    _physicScene->stepSimulation(time, 2);
}

void SceneSystem::EndFrame() {
    for (int i = 0; i < _objects->GetCount(); i++) {
        _objects->objectAtIndex(i)->EndFrame();
    }
}

void SceneSystem::Clear() {
    _visibleObjects->clear();
    _shadowObjects->clear();
    _objects->clear();
    
    IdGenerator::DefaultGenerator()->Reset();
}

shared_ptr<PivotObject> SceneSystem::GetObject(unsigned int objId) {
    for (int i = 0; i < _objects->GetCount(); i++) {
        if (_objects->objectAtIndex(i)->GetEditorAspect()->objectId() == objId) {
            return _objects->objectAtIndex(i);
        }
    }
    return nullptr;
}

void SceneSystem::DeleteObjects(UContainer<PivotObject> *objects) {
    
}

void SceneSystem::RemoveObject(const shared_ptr<PivotObject> object) {
    _objects->removeObject(object);
    //_sceneGraph.RemoveObject(deletingobjects);
    //deletingobjects.behaviourmodel.Disable();
    if (_objects->GetCount() == 0)
        IdGenerator::DefaultGenerator()->Reset();
}

