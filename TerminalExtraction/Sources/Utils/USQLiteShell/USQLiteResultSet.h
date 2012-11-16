//
//  USQLiteResultSet.h
//  TerminalExtraction
//
//  Created by  Developer on 16.11.12.
//
//

#ifndef __TerminalExtraction__USQLiteResultSet__
#define __TerminalExtraction__USQLiteResultSet__

#include <iostream>
#include <string>
#include <vector>


namespace Utils {
    
    class SQliteResultSet
    {
        std::string* _columnNames;
        std::vector<void*> *_result;
        
        int sqcallback(void* pCallbackArg, long argc, void* p2, void* p3);
        
    public:
        
        std::string* GetColumnNames() const { return _columnNames;}
        std::vector<void*>* GetResult() const { return _result;}
        
        
        SQliteResultSet(void* errorCallback);
        ~SQliteResultSet();

        
    };
    
}


#endif /* defined(__TerminalExtraction__USQLiteResultSet__) */
