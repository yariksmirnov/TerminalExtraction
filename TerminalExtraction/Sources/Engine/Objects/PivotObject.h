//
//  PivotObject.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/31/12.
//
//

#ifndef __TerminalExtraction__PivotObject__
#define __TerminalExtraction__PivotObject__

#include <iostream>
#include "TranslateableObject.h"

enum {
    PivotMaterialType_Stone,
    PivotMaterialType_Metal,
    PivotMaterialType_Wood,
    PivotMaterialType_DynamicMetal,
    PivotMaterialType_DynamicWood,
    PivotMaterialType_DynamicAtone,
    PivotMaterialType_DynamicAlive,
    PivotMaterialType_DynamicAlien
};
typedef unsigned int PivotMaterialType;

class PivotObject : public TranslateableObject {
    GLKMatrix3          _renderMatrix;
    GLKMatrix4          _transformMatrix;
    
    bool                _unloaded;
    
    int                 _materialType;
    
    bool                _needMouseCast;
    bool                _needBulletCast;
    bool                _needCalcAcxis;
    
public:
    
    GLKVector3 objectConstrAxis;
    GLKVector3 objectConstrForward;
    
    bool        moved;

    GLKMatrix3 renderMatrix();
    GLKMatrix4 transformMatrix();
    
};

#endif /* defined(__TerminalExtraction__PivotObject__) */
