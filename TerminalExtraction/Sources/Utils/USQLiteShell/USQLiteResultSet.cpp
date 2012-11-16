//
//  USQLiteResultSet.cpp
//  TerminalExtraction
//
//  Created by  Developer on 16.11.12.
//
//

#include "USQLiteResultSet.h"
#include "sqlite3.h"

using namespace std;

namespace Utils
{
    
    int SQliteResultSet::sqcallback(void* pCallbackArg, long argc, void* p2, void* p3)
    {
        return 0;
    }
    
    SQliteResultSet::SQliteResultSet(void* errorCallback)
    {
        
    }
    
    SQliteResultSet::~SQliteResultSet()
    {
        delete [] _columnNames;
        delete _result;
    }
}