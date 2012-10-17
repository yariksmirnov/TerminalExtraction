//
//  Display.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/18/12.
//
//

#include "Display.h"
#include "ios_display.h"

Display * Display::currentDisplay() {
//    if (!_current) {
//#ifdef TARGET_OS_IPHONE
//        _current = new iosDisplay();
//#else
//        
//#endif
//    }
    return new iosDisplay();
}

void Display::InitGLSurface() {
    throw "Virtual method";
}