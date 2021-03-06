//
//  LevelObject.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#ifndef __TerminalExtraction__LevelObject__
#define __TerminalExtraction__LevelObject__

#include <iostream>
#include "PivotObject.h"

class LevelObject : public PivotObject {
    
    RenderObject        *_renderAspect;
    Material            *_material;
public:
    

    
    LevelObject(RenderObject *renderObject, ObjectBehaviourModel *behaviorModel, Material *material);
    ~LevelObject();
    
    RenderObject * GetRenderAspect();
    Material * GetMaterial();
    
    static LevelObject * CreateCube();
    static LevelObject * CreatePlane();
    
    void Frame(double time);
    
};

#endif /* defined(__TerminalExtraction__LevelObject__) */
