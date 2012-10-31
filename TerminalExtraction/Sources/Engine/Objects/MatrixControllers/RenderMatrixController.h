//
//  RenderMatrixController.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/1/12.
//
//

#ifndef __TerminalExtraction__RenderMatrixController__
#define __TerminalExtraction__RenderMatrixController__

#include <iostream>
#include "Geometry.h"

class PivotObject;

class RenderMatrixController {
public:
    virtual GLKMatrix4 GetRenderMatrix(PivotObject *object) = 0;
};

#endif /* defined(__TerminalExtraction__RenderMatrixController__) */
