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

class LevelObjectDescription : public BaseDescription {
    
    string          _RCCMName;
    string          _materialName;
    string          _RODName;
    string          _characterName;
    string          _defaultAnimationName;
    string          _physicCollisionName;
    
    bool            _isRCCMEnabled;
    bool            _isRCCMAnimated;
    bool            _isAnimated;
    bool            _isStatic;
    
    
public:
    
    
};


#endif /* defined(__TerminalExtraction__LevelObjectDescription__) */
