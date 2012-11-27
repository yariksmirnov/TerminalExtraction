//
//  EngineSkinnedMesh.cpp
//  TerminalExtraction
//
//  Created by Anton Katekov on 26.11.12.
//
//

#include "EngineSkinnedMesh.h"
#include "BinaryReader.h"
#include "CharacterController.h"


const int vertexAnimSize = sizeof(vertexAnimStruct);
const size_t vertexPositionOffset = offsetof(vertexAnimStruct,position);
const size_t vertexNormalOffset = offsetof(vertexAnimStruct,normal);
const size_t vertexTcoordOffset = offsetof(vertexAnimStruct,tcoord);
const size_t vertexIndicesOffset = offsetof(vertexAnimStruct,indices);
const size_t vertexCoefficientsOffset = offsetof(vertexAnimStruct,coefficients);

EngineSkinnedMesh::EngineSkinnedMesh()
{
    _disposed = true;
}

EngineSkinnedMesh::EngineSkinnedMesh(void * vertices, long vSize, void *indices, long iSize)
{
    glEnable(GL_DEPTH_TEST);
    
    glGenBuffers(1, &_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vSize, vertices, GL_STATIC_DRAW);
    
    glGenBuffers(1, &_indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, iSize, indices, GL_STATIC_DRAW);
    
    _primitivesCount = iSize/sizeof(GLushort);
    
    _disposed = false;
}


EngineSkinnedMesh::~EngineSkinnedMesh()
{
    Dispose();
}

void EngineSkinnedMesh::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glEnableVertexAttribArray(ATTRIB_VERTEX);
    glVertexAttribPointer(ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE, vertexAnimSize, (void*)vertexPositionOffset);
    glEnableVertexAttribArray(ATTRIB_NORMAL);
    glVertexAttribPointer(ATTRIB_NORMAL, 3, GL_FLOAT, GL_FALSE, vertexAnimSize, (void*)vertexNormalOffset);
    glEnableVertexAttribArray(ATTRIB_TCOORD);
    glVertexAttribPointer(ATTRIB_TCOORD, 2, GL_FLOAT, GL_FALSE, vertexAnimSize, (void*)vertexTcoordOffset);
    glEnableVertexAttribArray(ATTRIB_INDICES);
    glVertexAttribPointer(ATTRIB_INDICES, 3, GL_FLOAT, GL_FALSE, vertexAnimSize, (void*)vertexIndicesOffset);
    glEnableVertexAttribArray(ATTRIB_COEFFICIENTS);
    glVertexAttribPointer(ATTRIB_COEFFICIENTS, 3, GL_FLOAT, GL_FALSE, vertexAnimSize, (void*)vertexCoefficientsOffset);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);

}

void EngineSkinnedMesh::Render() const
{
    glDrawElements(GL_TRIANGLES, _primitivesCount, GL_UNSIGNED_SHORT, (void*)0);
}

void EngineSkinnedMesh::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void EngineSkinnedMesh::Dispose()
{
    if(_disposed)
        return;
    
    glDeleteBuffers(1, &_vertexBuffer);
    glDeleteBuffers(1, &_indexBuffer);
    _disposed = true;
}
//todo
void EngineSkinnedMesh::LoadFromBuffer(char *buffer, unsigned int bufferLength)
{
    BinaryReader br(buffer, bufferLength);
    
    int verticesCount = br.ReadInt();
    int indicesCount = br.ReadInt();
    
    GLsizeiptr vSize = vertexAnimSize * verticesCount;
    GLsizeiptr iSize = sizeof(GLushort) * indicesCount;
    
    GLfloat* vertices = (GLfloat*)malloc(vSize);
    for(int i = 0;i < verticesCount; i++)
    {
        int baseStride = vertexAnimSize * i/ sizeof(GLfloat);
        vertices[baseStride] = br.ReadSingle();
        vertices[baseStride + 1] = br.ReadSingle();
        vertices[baseStride + 2] = br.ReadSingle();
        
        
        vertices[baseStride + 3] = br.ReadSingle();
        vertices[baseStride + 4] = br.ReadSingle();
        vertices[baseStride + 5] = br.ReadSingle();
        
        
        vertices[baseStride + 6] = br.ReadSingle();
        vertices[baseStride + 7] = br.ReadSingle();
        
        
        int f = br.ReadInt();
        for (int j = 0; j < f; j++)
            br.ReadString();
        
        f = br.ReadInt();
        for (int j = 0; j < f; j++)
            br.ReadSingle();
    }
    
    GLushort* indices = (GLushort*)malloc(iSize);
    for(int i = 0;i < indicesCount; i++)
        indices[i] = (GLushort)br.ReadInt();
    
    
    
    glEnable(GL_DEPTH_TEST);
    
    glGenBuffers(1, &_vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vSize, vertices, GL_STATIC_DRAW);
    
    glGenBuffers(1, &_indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, iSize, indices, GL_STATIC_DRAW);
    
    _primitivesCount = iSize/sizeof(GLushort);
    _disposed = false;
    
    free(vertices);
    free(indices);

}