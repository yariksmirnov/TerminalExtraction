//
//  PEBaseDescription.h
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#ifndef __TerminalExtraction__PEBaseDescription__
#define __TerminalExtraction__PEBaseDescription__

#include <iostream>
#include <string>

using namespace std;

class BaseDescription {
    
    unsigned int _id;

public:
    
    unsigned int GetId () const { return _id; };
    
    BaseDescription(unsigned int id);
    
    virtual void mapValueWithName(void* value, string name);
};

#endif /* defined(__TerminalExtraction__PEBaseDescription__) */
