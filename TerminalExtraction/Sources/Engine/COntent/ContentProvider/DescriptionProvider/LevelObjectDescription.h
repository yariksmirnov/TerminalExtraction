//
//  LevelObjectDescription.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/19/12.
//
//

#ifndef __TerminalExtraction__LevelObjectDescription__
#define __TerminalExtraction__LevelObjectDescription__

#include <iostream>
#include "BaseDescription.h"

using namespace std;

class BehaviourModelDescription;

class LevelObjectDescription : public BaseDescription {
    
    int          _RCBOId;
    int          _matId;
    int          _RODId;
    BehaviourModelDescription          *_behavourModelDescription;
    
public:
    
    
};


#endif /* defined(__TerminalExtraction__LevelObjectDescription__) */
