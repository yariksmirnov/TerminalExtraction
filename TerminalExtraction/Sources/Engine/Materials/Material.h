//
//  Material.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/1/12.
//
//

#ifndef __TerminalExtraction__Material__
#define __TerminalExtraction__Material__

#include <iostream>

class Material {
public:
    
    virtual void SetFrame(int frame) = 0;
    virtual bool UseBackgroundLoading();
    virtual bool IsMultiFrame();
    virtual void StopBackgroundLoading() = 0;
    
    
};

#endif /* defined(__TerminalExtraction__Material__) */
