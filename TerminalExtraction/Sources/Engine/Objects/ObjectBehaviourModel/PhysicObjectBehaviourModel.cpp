//
//  PhysicObjectBehaviourModel.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/14/12.
//
//

#include "PhysicObjectBehaviourModel.h"
#include "bulletAddons.h"
#include "btDefaultMotionState.h"

PhysicObjectBehaviuorModel::PhysicObjectBehaviuorModel(btRigidBody *rigidBody):ObjectBehaviourModel()
{
    _rigidBody = rigidBody;
//    _rigidBody->setLinearVelocity(btVector3());
//    _rigidBody->setLinearFactor(btVector3());
//    _rigidBody->setAngularVelocity(btVector3());
//    _rigidBody->setAngularFactor(0);
}

PhysicObjectBehaviuorModel::~PhysicObjectBehaviuorModel()
{
    delete _rigidBody;
}

void PhysicObjectBehaviuorModel::Frame(double time)
{
    moved = true;
    btTransform tr;
    _rigidBody->getMotionState()->getWorldTransform(tr);
    _currentPosition = btTransformToMatrix4(tr);
}

void PhysicObjectBehaviuorModel::Enable()
{
    
}

void PhysicObjectBehaviuorModel::Disable()
{
    
}

void PhysicObjectBehaviuorModel::Rotate(float angle)
{
}

void PhysicObjectBehaviuorModel::Move(GLKVector3 displacement)
{
    
}

void PhysicObjectBehaviuorModel::MakeJolt(GLKVector3 point, GLKVector3 direction, float mass)
{
    
}

void PhysicObjectBehaviuorModel::SetGlobalPosition(const GLKMatrix4& globalPosition, void * aditionalData, const PivotObject *parent, bool afterUpdate)
{
    _rigidBody->getMotionState()->setWorldTransform(btTransformFromMatrix4(globalPosition));

    _rigidBody->activate(true);
    if(afterUpdate)
        this->Frame(0);
}

void PhysicObjectBehaviuorModel::SetPosition(const GLKMatrix4& position)
{
    SetGlobalPosition(position, nullptr, nullptr, true);
}

void PhysicObjectBehaviuorModel::SetParentObject(const PivotObject *parent)
{}
