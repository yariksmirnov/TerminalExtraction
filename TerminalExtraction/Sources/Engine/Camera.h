//
//  Camera.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/30/12.
//
//

#ifndef __TerminalExtraction__Camera__
#define __TerminalExtraction__Camera__

#include <iostream>
#include "Geometry.h"

class Camera {
    
    GLfloat             _cameraPitch;
    
    GLfloat             _far;
    GLfloat             _aspectRatio;
    
    //BoundingFrustum cameraFrustum;
    
    GLKVector3          _target;
    
    GLKVector3          _farLeftTop;
    GLKVector3          _farRightTop;
    GLKVector3          _farLeftBottom;
    GLKVector3          _farRightBottom;
    
    void UpdateAfterSet();
    
public:
    
    GLKMatrix4          projection;
    GLKMatrix4          view;
    
    GLKVector3          position;
    GLKVector3          direction;
    
    GLfloat             maxDepth;
    GLfloat             minDepth;
    GLfloat             cameraYaw;
    
    GLKVector2          cameraXZProj;
    GLKVector3          cameraUp;
    
    GSize2D             screenSize;
    
    
    Camera(GLKVector3 cameraPosition, GLKVector3 cameraTarget, GRect2D bounds);
    
    ~Camera();
    
    void Update(GLKVector3 cameraPosition, GLKVector3 cameraTarget);
    void Update(GLKVector3 cameraPosition);
    void Update(GLfloat yawDelta, GLfloat rDelta);
};

#endif /* defined(__TerminalExtraction__Camera__) */
