//
//  EngineSkinnedMesh.h
//  TerminalExtraction
//
//  Created by Anton Katekov on 26.11.12.
//
//

#ifndef __TerminalExtraction__EngineSkinnedMesh__
#define __TerminalExtraction__EngineSkinnedMesh__

#include <iostream>
#include "PackObjectInterface.h"
#include "Geometry.h"

class Character;

class EngineSkinnedMesh: public PackObjectInterface {
    
    
    GLuint          _indexBuffer;
    GLuint          _vertexBuffer;
    
    long            _vSize;
    long            _iSize;
    long            _primitivesCount;
    
    Character      *_character;
    
public:
    
    void SetCharacter(Character* character) {_character = character; }
    Character *GetCharacter() const { return _character; }
    
    EngineSkinnedMesh();
    EngineSkinnedMesh(void * vertices, long vSize, void *indices, long iSize);
    
    
    ~EngineSkinnedMesh();
    
    void Bind() const;
    void Render() const;
    void Unbind() const;
    
    
    virtual void Dispose();
    virtual void LoadFromBuffer(char *buffer, unsigned int bufferLength);
    
};

#endif /* defined(__TerminalExtraction__EngineSkinnedMesh__) */
