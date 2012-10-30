//
//  Camera.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/30/12.
//
//

#include "Camera.h"


Camera::Camera(GLKVector3 cameraPosition, GLKVector3 cameraTarget, GRect2D bounds) {
    
    position = cameraPosition;
    _target  = cameraTarget;
    
    direction = GLKVector3Subtract(_target,position);
    direction = GLKVector3Normalize(direction);
    
    float katet = -(cameraTarget.y - cameraPosition.y);
    float gipotenuza = GLKVector3Length(GLKVector3Subtract(cameraPosition, cameraTarget));
    
    _cameraPitch =  acosf(katet / gipotenuza);
    float determ = (cameraTarget.z - cameraPosition.z);
    if (determ == 0)
        determ = 0.001f;
    cameraYaw = (atanf((cameraTarget.x - cameraPosition.x) / determ));
    
    
    view =  GLKMatrix4MakeLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z, cameraTarget.x, cameraTarget.y, cameraTarget.z, 0, 1, 0);
    _aspectRatio = fabsf(bounds.size.width / bounds.size.height);
    _far = 100.0f;
    projection = GLKMatrix4MakePerspective(GLKMathDegreesToRadians(65.0f),
                                            _aspectRatio,
                                            0.1f,
                                            _far);
    cameraXZProj.x = position.x;
    cameraXZProj.y = position.z;
    
    minDepth = 0.1;
    maxDepth = 100.0;
    screenSize = bounds.size;

}

void Camera::Update(GLKVector3 cameraPosition) {
    Update(cameraPosition, _target);
}

void Camera::Update(GLKVector3 cameraPosition, GLKVector3 cameraTarget) {
    
    position = cameraPosition;
    _target = cameraTarget;
    cameraXZProj.x = position.x;
    cameraXZProj.y = position.z;
    direction = GLKVector3Subtract(_target, position);
    float gipotenuza = GLKVector3Length(direction);
    direction = GLKVector3Normalize(direction);
    
    float katet = -(cameraTarget.y - cameraPosition.y);
    _cameraPitch = acosf(katet / gipotenuza);
    float determ = (cameraTarget.z - cameraPosition.z);
    if (determ == 0)
        determ = 0.001f;
    cameraYaw =atanf((cameraTarget.x - cameraPosition.x) / determ);
    view = GLKMatrix4MakeLookAt(cameraPosition.x, cameraPosition.y, cameraPosition.z, cameraTarget.x, cameraTarget.y, cameraTarget.z, 0, 1, 0);
    
    UpdateAfterSet();
}

void Camera::UpdateAfterSet()
{
    cameraUp.x = view.m10;
    cameraUp.y = view.m11;
    cameraUp.z = view.m12;
}