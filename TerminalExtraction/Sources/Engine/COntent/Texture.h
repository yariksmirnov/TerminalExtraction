//
//  Texture.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#ifndef __TerminalExtraction__Texture__
#define __TerminalExtraction__Texture__

#include <iostream>
#include "PackObjectInterface.h"
#include "Geometry.h"

using namespace std;

class Texture : public PackObjectInterface {
    
    GLuint          _name;
    bool            _fromFile;
    
    GLfloat         _texWidth;
    GLfloat         _texHeight;
    
    string          _textureFilename;
    
    GLuint SetupTexture(GLubyte *spriteData);
    
public:
    
    Texture();
    Texture(string filename);
    
    GLuint GetTextureName();
    
    
    virtual void Dispose();
    virtual void LoadFromBuffer(char *buffer, unsigned int bufferLength);
    
    ~Texture();
};

#endif /* defined(__TerminalExtraction__Texture__) */
