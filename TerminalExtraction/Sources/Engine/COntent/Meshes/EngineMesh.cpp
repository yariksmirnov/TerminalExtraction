//
//  EngineMesh.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "EngineMesh.h"


const int vertexSize = sizeof(vertexStruct);
const size_t vertexPositionOffset = offsetof(vertexStruct,position);
const size_t vertexNormalOffset = offsetof(vertexStruct,normal);
const size_t vertexTcoordOffset = offsetof(vertexStruct,tcoord);

GLfloat cubeVertexData[288] =
{
    // Data layout for each line below is:
    // positionX, positionY, positionZ,     normalX, normalY, normalZ,  tccordX, tcoordY
    0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 1.0f,1,0,
    0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f,1,0,
    0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 1.0f,0,0,
    0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 1.0f,1,0,
    0.5f, 0.5f, 0.5f,          1.0f, 0.0f, 0.0f,1,0,
    0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f,0,0,
    
    0.5f, 0.5f, -0.5f,         0.0f, 1.0f, 0.0f,0,0,
    -0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f,0,0,
    0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f,0,0,
    0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f,0,0,
    -0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f,0,0,
    -0.5f, 0.5f, 0.5f,         0.0f, 1.0f, 0.0f,0,0,
    
    -0.5f, 0.5f, -0.5f,        -1.0f, 0.0f, 0.0f,0,0,
    -0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f,0,0,
    -0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f,0,0,
    -0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f,0,0,
    -0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f,0,0,
    -0.5f, -0.5f, 0.5f,        -1.0f, 0.0f, 0.0f,0,0,
    
    -0.5f, -0.5f, -0.5f,       0.0f, -1.0f, 0.0f,0,0,
    0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f,0,0,
    -0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f,0,0,
    -0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f,0,0,
    0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f,0,0,
    0.5f, -0.5f, 0.5f,         0.0f, -1.0f, 0.0f,0,0,
    
    0.5f, 0.5f, 0.5f,          0.0f, 0.0f, 1.0f,0,0,
    -0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f,0,0,
    0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f,0,0,
    0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f,0,0,
    -0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f,0,0,
    -0.5f, -0.5f, 0.5f,        0.0f, 0.0f, 1.0f,0,0,
    
    0.5f, -0.5f, -0.5f,        0.0f, 0.0f, -1.0f,0,0,
    -0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f,0,0,
    0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f,0,0,
    0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f,0,0,
    -0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f,0,0,
    -0.5f, 0.5f, -0.5f,        0.0f, 0.0f, -1.0f,0,0
};

GLushort cubeIndexData[36] =
{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35};

GLfloat planeVertexData[48] =
{
    // Data layout for each line below is:
    // positionX, positionY, positionZ,     normalX, normalY, normalZ,   tccordX, tcoordY
    0.05f, 0.5f, 0.0f,          0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
    -0.05f, 0.5f, 0.0f,         0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
    0.05f, -0.5f, 0.0f,         0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
    0.05f, -0.5f, 0.0f,         0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
    -0.05f, 0.5f, 0.0f,         0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
    -0.05f, -0.5f, 0.0f,        0.0f, 0.0f, 1.0f,   0.0f, 0.0f
};

GLfloat squarePlaneVertexData[48] =
{
    // Data layout for each line below is:
    // positionX, positionY, positionZ,     normalX, normalY, normalZ,   tccordX, tcoordY
    0.5f, 0.5f, 0.0f,          0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
    -0.5f, 0.5f, 0.0f,         0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
    0.5f, -0.5f, 0.0f,         0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
    0.5f, -0.5f, 0.0f,         0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
    -0.5f, 0.5f, 0.0f,         0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
    -0.5f, -0.5f, 0.0f,        0.0f, 0.0f, 1.0f,   0.0f, 0.0f
};

GLfloat screenQuadVertexData[48] =
{
    // Data layout for each line below is:
    // positionX, positionY, positionZ,     normalX, normalY, normalZ,   tccordX, tcoordY
    -1.0f, -1.0f, 0.0f,         0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
    1.0f, 1.0f, 0.0f,         0.0f, 0.0f, 1.0f,   1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,         0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
    -1.0f, -1.0f, 0.0f,         0.0f, 0.0f, 1.0f,   0.0f, 1.0f,
    -1.0f, 1.0f, 0.0f,         0.0f, 0.0f, 1.0f,   0.0f, 0.0f,
    1.0f, 1.0f, 0.0f,         0.0f, 0.0f, 1.0f,   1.0f, 0.0f
};

GLushort planeIndexData[6] =
{0,1,2,3,4,5};


EngineMesh::EngineMesh(void * vertices, long vSize, void *indices, long iSize):_vSize(vSize), _iSize(iSize)
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

void EngineMesh::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, _vertexBuffer);
    glVertexAttribPointer(ATTRIB_VERTEX, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)vertexPositionOffset);
    glEnableVertexAttribArray(ATTRIB_VERTEX);
    glVertexAttribPointer(ATTRIB_NORMAL, 3, GL_FLOAT, GL_FALSE, vertexSize, (void*)vertexNormalOffset);
    glEnableVertexAttribArray(ATTRIB_NORMAL);
    glVertexAttribPointer(ATTRIB_TCOORD, 2, GL_FLOAT, GL_FALSE, vertexSize, (void*)vertexTcoordOffset);
    glEnableVertexAttribArray(ATTRIB_TCOORD);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
}

void EngineMesh::Unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EngineMesh::Dispose()
{
    if(_disposed)
        return;
    
    
    glDeleteBuffers(1, &_vertexBuffer);
    glDeleteBuffers(1, &_indexBuffer);
    _disposed = true;
}

EngineMesh::~EngineMesh()
{
    Dispose();
}

void EngineMesh::Render() const {
    glDrawElements(GL_TRIANGLES, _primitivesCount, GL_UNSIGNED_SHORT, (void*)0);
}

const EngineMesh * EngineMesh::CreateCube() {
    return const_cast<const EngineMesh *>(new  EngineMesh(cubeVertexData, sizeof(cubeVertexData), cubeIndexData, sizeof(cubeIndexData)));
}

const EngineMesh * EngineMesh::CreateFullscreenQuad()
{
    return const_cast<const EngineMesh *>(new EngineMesh(screenQuadVertexData, sizeof(screenQuadVertexData), planeIndexData, sizeof(planeIndexData)));
}

