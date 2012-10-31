//
//  ObjectBehaviourModel.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/1/12.
//
//

#include "ObjectBehaviourModel.h"


ObjectBehaviourModel::ObjectBehaviourModel() {
    _currentPosition = GLKMatrix4Identity;
    _globalPosition = GLKMatrix4Identity;
}

GLKMatrix4 ObjectBehaviourModel::GetGlobalPosition() {
    return _globalPosition;
}

void ObjectBehaviourModel::SetGlobalPosition(GLKMatrix4 globalPosition, void *aditionalData, PivotObject *parent, bool afterUpdate) {
    
}

void ObjectBehaviourModel::CommitPosition() {
    moved = ((_globalPosition.m30 != _currentPosition.m30) || (_globalPosition.m31 != _currentPosition.m31) || (_globalPosition.m32 != _currentPosition.m32));
    _globalPosition = _currentPosition;
}

void ObjectBehaviourModel::BeginFrame() {
    moved = false;
}

void ObjectBehaviourModel::Frame(double time) {
    
}

void ObjectBehaviourModel::EndFrame() {
    moved = moved || ((_globalPosition.m30 != _currentPosition.m30) || (_globalPosition.m31 != _currentPosition.m31) || (_globalPosition.m32 != _currentPosition.m32));
    _globalPosition = _currentPosition;

}

void ObjectBehaviourModel::Enable() {
    
}

void ObjectBehaviourModel::Disale() {
    
}

void ObjectBehaviourModel::Rotate(float angle) {
    
}

void ObjectBehaviourModel::Move(GLKVector3 displacement) {
    
}

void ObjectBehaviourModel::MakeJolt(GLKVector3 point, GLKVector3 direction, float mass) {
    
}