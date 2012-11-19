//
//  PEContentProvider.h
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#ifndef __TerminalExtraction__PEContentProvider__
#define __TerminalExtraction__PEContentProvider__

#include <iostream>
#include "Utils.h"
#include <vector>

using namespace Kompex;

class LevelObject;

class ContentProvider {
     SQLiteDatabase      *_database;
    
    
public:
    ContentProvider();
    ~ContentProvider();
};


#endif /* defined(__TerminalExtraction__PEContentProvider__) */
