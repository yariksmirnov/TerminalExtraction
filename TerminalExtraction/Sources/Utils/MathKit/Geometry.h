//
//  MathKit.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/30/12.
//
//

#ifndef TerminalExtraction_MathKit_h
#define TerminalExtraction_MathKit_h

#include "GlobalConstants.h"

#include GLES2

struct __GPoint2D {
    GLfloat x;
    GLfloat y;
};

struct __GSize2D {
    GLfloat height;
    GLfloat width;
};

struct __GRect2D {
    struct __GPoint2D   origin;
    struct __GSize2D    size;
};


typedef struct __GPoint2D GPoint2D;
typedef struct __GRect2D GRect2D;
typedef struct __GSize2D GSize2D;

#include "GLKMath.h"
#include "MyMath.h"

#endif
