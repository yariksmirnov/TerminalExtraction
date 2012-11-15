//
//  PhysicObjectBehaviourModel.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/14/12.
//
//

#ifndef __TerminalExtraction__PhysicObjectBehaviourModel__
#define __TerminalExtraction__PhysicObjectBehaviourModel__

#include <iostream>
#include "ObjectBehaviourModel.h"
#include "btRigidBody.h"

class PhysicObjectBehaviuorModel : public ObjectBehaviourModel  {

    btRigidBody             *_rigidBody;
    
    
public:
    
    PhysicObjectBehaviuorModel(btRigidBody *_rigidBody);
    ~PhysicObjectBehaviuorModel();
    
    btRigidBody * GetRigidBody() const { return _rigidBody; };

    void Frame(double time);

    void Disable();
    void Enable();
    
    void Rotate(float angle);
    void Move(GLKVector3 displacement);
    
    void MakeJolt(GLKVector3 point, GLKVector3 direction, float mass);
    
    void SetGlobalPosition(const GLKMatrix4& globalPosition, void * aditionalData, const PivotObject *parent, bool afterUpdate);
    void SetPosition(const GLKMatrix4& position);
    void SetParentObject(const PivotObject *parent);


    

};

#endif /* defined(__TerminalExtraction__PhysicObjectBehaviourModel__) */
