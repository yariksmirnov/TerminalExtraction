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
    
    GLKMatrix4      _currentPosition;
    GLKMatrix4      _globalPosition;
    
public:
    
    bool            moved;
    
    ObjectBehaviourModel();
    
    GLKMatrix4 GetGlobalPosition();
    void SetGlobalPosition(GLKMatrix4 globalPosition, void * aditionalData, PivotObject *parent, bool afterUpdate);
    void SetParentObject(PivotObject *parent);
    
    void SetPosition(GLKMatrix4 position);
    void CommitPosition();
    
    void BeginFrame();
    void EndFrame();
    void Frame(double time);
    
    void Enable();
    void Disale();
    
    void Rotate(float angle);
    void Move(GLKVector3 displacement);

    void MakeJolt(GLKVector3 point, GLKVector3 direction, float mass);

};

#endif /* defined(__TerminalExtraction__ObjectBehaviourModel__) */
