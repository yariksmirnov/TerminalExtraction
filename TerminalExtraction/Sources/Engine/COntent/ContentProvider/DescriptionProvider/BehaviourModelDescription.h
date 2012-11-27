//
//  BehaviourModelDescription.h
//  TerminalExtraction
//
//  Created by Anton Katekov on 27.11.12.
//
//

#ifndef __TerminalExtraction__BehaviourModelDescription__
#define __TerminalExtraction__BehaviourModelDescription__

#include <iostream>
#include <string>
#include "BaseDescription.h"
#include "Geometry.h"

using namespace std;

class BehaviourModelDescription : public BaseDescription{

public:
    int             _type;
    bool            _isStatic;
    GLKVector3      _centerOfMass;
    int             _shapeType;
    int             _physicShapeType;
    GLKVector3      _shapeSize;
    float           _shapeRotationAngle;
    GLKVector3      _shapeRotationAxis;
    string          _collisionMeshName;
    float           _mass;
    
    BehaviourModelDescription(unsigned int      id);
    BehaviourModelDescription(unsigned int      id,
                              int               type,
                              bool              isStatic,
                              GLKVector3        centerOfMass,
                              int               shapeType,
                              int               physicShapeType,
                              GLKVector3        shapeSize,
                              float             shapeRotationAngle,
                              GLKVector3        shapeRotationAxis,
                              string            collisionMeshName,
                              float             mass);
    
    virtual void mapValueWithName(void* value, string name);
};



#endif /* defined(__TerminalExtraction__BehaviourModelDescription__) */
