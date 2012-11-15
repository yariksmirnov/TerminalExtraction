//
//  ObjectBehaviourModel.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/1/12.
//
//

#ifndef __TerminalExtraction__ObjectBehaviourModel__
#define __TerminalExtraction__ObjectBehaviourModel__

#include <iostream>

#include "Geometry.h"

class PivotObject;

class ObjectBehaviourModel {
protected:
    
    GLKMatrix4      _currentPosition;
    GLKMatrix4      _globalPosition;
    
public:
    
    bool            moved;
    
    ObjectBehaviourModel();
    virtual ~ ObjectBehaviourModel();
    
    GLKMatrix4 GetGlobalPosition();
    virtual void SetGlobalPosition(const GLKMatrix4& globalPosition, void * aditionalData, const PivotObject *parent, bool afterUpdate);
    virtual void SetPosition(const GLKMatrix4& position);
    virtual void SetParentObject(const PivotObject *parent);
    
    void CommitPosition();
    
    void BeginFrame();
    void EndFrame();
    virtual void Frame(double time);
    
    virtual void Enable();
    virtual void Disale();
    virtual void Rotate(float angle);
    virtual void Move(GLKVector3 displacement);
    virtual void MakeJolt(GLKVector3 point, GLKVector3 direction, float mass);

};

#endif /* defined(__TerminalExtraction__ObjectBehaviourModel__) */
