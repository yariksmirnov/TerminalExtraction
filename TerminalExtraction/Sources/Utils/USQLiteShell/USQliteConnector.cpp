//
//  USQliteConnector.cpp
//  TerminalExtraction
//
//  Created by  Developer on 16.11.12.
//
//

#include "USQliteConnector.h"

using namespace std;

namespace Utils {
    
   
    SQliteConnector::SQliteConnector(string dbname)
    {}
    
    SQliteConnector::~SQliteConnector()
    {
        if(!_closed)
            Close();
    }
    
    void  SQliteConnector::executeNonQuery(string query, void* errorCallback)
    {}
       
    USQLiteResultSet* SQliteConnector::executeSelect(string query, void* errorCallback)
    {
        return nullptr;
    }
    
    int SQliteConnector::executeInsert(string query, void* errorCallback)
    {
        return 0;
    }
        
    void SQliteConnector::Close()
    {}
    
}