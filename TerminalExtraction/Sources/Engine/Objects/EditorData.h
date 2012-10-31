//
//  EditorData.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/1/12.
//
//

#ifndef __TerminalExtraction__EditorData__
#define __TerminalExtraction__EditorData__

#include <iostream>
#include <stdlib.h>

using namespace std;

class EditorData {
    
    string          _descriptiongName;
    int             _objectType;
    unsigned int    _objectId;
    
public:
    
    unsigned int objectId();
    
    EditorData(string descrName, int type);
    
};

#endif /* defined(__TerminalExtraction__EditorData__) */
