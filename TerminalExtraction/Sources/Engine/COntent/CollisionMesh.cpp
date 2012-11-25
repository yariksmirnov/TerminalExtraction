//
//  CollisionMesh.cpp
//  TerminalExtraction
//
//  Created by  Developer on 25.11.12.
//
//

#include "CollisionMesh.h"
#include "BinaryReader.h"

CollisionMesh::CollisionMesh()
{
    _disposed = true;
}

CollisionMesh::~CollisionMesh()
{
    if (!_disposed)
        Dispose();
}

void CollisionMesh::Dispose()
{
    if(_disposed)
        return;
    
    _disposed = true;
    free(_indices);// delete[] _indices;
    free(_vertices);//delete[] _vertices;
}

void CollisionMesh::LoadFromBuffer(char *buffer, unsigned int bufferLength)
{
    BinaryReader br(buffer, bufferLength);
    _verticesCount = br.ReadInt();
    
    _vertices = (GLKVector3*)malloc(_verticesCount * 4 * 3);// new GLKVector3[vCount];
    br.ReadBuffer(_verticesCount * 4 * 3, (char*)_vertices);
    
    _indicesCount = br.ReadInt();
    _indices = (int*)malloc(_indicesCount * 4);// new int[iCount];
    br.ReadBuffer(_indicesCount * 4, (char*)_indices);
}