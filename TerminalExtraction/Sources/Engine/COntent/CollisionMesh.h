//
//  CollisionMesh.h
//  TerminalExtraction
//
//  Created by  Developer on 25.11.12.
//
//

#ifndef __TerminalExtraction__CollisionMesh__
#define __TerminalExtraction__CollisionMesh__

#include <iostream>
#include "PackObjectInterface.h"
#include "Geometry.h"

class CollisionMesh : public PackObjectInterface {
    
    GLKVector3* _vertices;
    int* _indices;
    
    int _verticesCount;
    int _indicesCount;
    
    bool _disposed;
    
public:
    
    GLKVector3* GetVertices() const {return _vertices; };
    int* GetIndices() {return _indices; };
    
    int GetVerticesCount() const { return _verticesCount; };
    int GetIndicesCount() const { return _indicesCount; };

    CollisionMesh();
    ~CollisionMesh();
    
    virtual void Dispose();
    virtual void LoadFromBuffer(char *buffer, unsigned int bufferLength);
};

#endif /* defined(__TerminalExtraction__CollisionMesh__) */
