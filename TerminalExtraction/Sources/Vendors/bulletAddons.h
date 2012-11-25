//
//  bulletAddons.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/15/12.
//
//

#ifndef TerminalExtraction_bulletAddons_h
#define TerminalExtraction_bulletAddons_h

#include "CollisionMesh.h"
#include "btConvexHullShape.h"
#include "btTriangleMeshShape.h"
inline GLKMatrix4 btTransformToMatrix4(const btTransform& t)
{
    GLKMatrix4 result;
    t.getOpenGLMatrix(result.m);
    return result;
}

inline btTransform btTransformFromMatrix4(GLKMatrix4 mat) {
    btTransform t;
    t.setFromOpenGLMatrix(mat.m);
    return t;
}

inline btVector3 btVector3FromGLKVector3(GLKVector3 mat) {
    return btVector3(mat.x, mat.y, mat.z);
}

inline btConvexHullShape* btCollisionShapeFromCollisionMesh(const CollisionMesh* cm)
{
    btConvexHullShape* resut = new btConvexHullShape();
    GLKVector3* vertices = cm->GetVertices();
    int count = cm->GetVerticesCount();
    for (int i = 0; i < count; i++)
        resut->addPoint(btVector3FromGLKVector3(vertices[i]));
    
    return resut;
}

//inline btTriangleMesh* btCollisionShapeFromCollisionMesh(CollisionMesh* cm)
//{
//    
//}

#endif
