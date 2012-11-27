//
//  BehaviourModelDescription.cpp
//  TerminalExtraction
//
//  Created by Anton Katekov on 27.11.12.
//
//

#include "BehaviourModelDescription.h"

BehaviourModelDescription::BehaviourModelDescription(unsigned int      id):
BaseDescription(id)
{}

BehaviourModelDescription::BehaviourModelDescription(unsigned int      id,
                          int               type,
                          bool              isStatic,
                          GLKVector3        centerOfMass,
                          int               shapeType,
                          int               physicShapeType,
                          GLKVector3        shapeSize,
                          float             shapeRotationAngle,
                          GLKVector3        shapeRotationAxis,
                          string            collisionMeshName,
                          float             mass):
BaseDescription(id),
_type(type),
_isStatic(isStatic),
_centerOfMass(centerOfMass),
_shapeType(shapeType),
_physicShapeType(physicShapeType),
_shapeSize(shapeSize),
_shapeRotationAngle(shapeRotationAngle),
_shapeRotationAxis(shapeRotationAxis),
_collisionMeshName(collisionMeshName),
_mass(mass)
{}

void BehaviourModelDescription::mapValueWithName(void *value, string name)
{
    if (name == "type") {
        memcpy(&_type, value, 4);
    }
    //...
}