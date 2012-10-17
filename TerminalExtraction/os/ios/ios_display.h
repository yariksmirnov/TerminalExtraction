//
//  ios_display.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#ifndef __TerminalExtraction__ios_display__
#define __TerminalExtraction__ios_display__

#include <iostream>
#include "Display.h"

class iosDisplay : public Display {
    
public:
    virtual void InitGLSurface();
};

#endif /* defined(__TerminalExtraction__ios_display__) */
