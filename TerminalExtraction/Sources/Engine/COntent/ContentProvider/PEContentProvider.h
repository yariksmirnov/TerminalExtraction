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

using namespace Kompex;

class LevelObject;

class PEContentProvider
{
     Kompex::SQLiteDatabase      *_database;
    
public:
    PEContentProvider();
    ~PEContentProvider();
};


#endif /* defined(__TerminalExtraction__PEContentProvider__) */
