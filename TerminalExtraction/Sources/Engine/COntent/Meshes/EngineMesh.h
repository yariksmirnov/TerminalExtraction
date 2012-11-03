//
//  EngineMesh.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#ifndef __TerminalExtraction__EngineMesh__
#define __TerminalExtraction__EngineMesh__

#include <iostream>

#include "Geometry.h"

class EngineMesh {
    
    bool            _disposed;
    
    GLuint          _indexBuffer;
    GLuint          _vertexBuffer;
    
    long            _vSize;
    long            _iSize;
    long            _primitivesCount;
    
public:
    
    EngineMesh();
    EngineMesh(void * vertices, long vSize, void *indices, long iSize);
    
    void Bind();
    void Render();
    void Unbind();
    void Dispose();
    
    ~EngineMesh();
    
    static const EngineMesh * CreateCube(void);
    static const EngineMesh * CreateFullscreenQuad(void);
    
};

#endif /* defined(__TerminalExtraction__EngineMesh__) */

