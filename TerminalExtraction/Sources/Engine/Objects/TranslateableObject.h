//
//  TranslateableObject.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/31/12.
//
//

#ifndef TerminalExtraction_TranslateableObject_h
#define TerminalExtraction_TranslateableObject_h

#include "Geometry.h"

class TranslateableObject {
    
public:
    
    virtual GLKVector3 GetPosition() = 0;
    virtual void SetPosition(GLKVector3 position) = 0;
    
};

#endif
