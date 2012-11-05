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

#include "Geometry.h"

using namespace std;

class Texture {
    
    bool            _disposed;
    GLuint          _name;
    bool            _fromFile;
    
    GLfloat         _texWidth;
    GLfloat         _texHeight;
    
    string          _textureFilename;
    
    GLuint SetupTexture(GLubyte *spriteData);
    
public:
    
    Texture(string filename);
    
    GLuint GetTextureName();
    
    
    void Dispose();
    ~Texture();
};

#endif /* defined(__TerminalExtraction__Texture__) */
