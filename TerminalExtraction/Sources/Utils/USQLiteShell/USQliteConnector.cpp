//
//  USQliteConnector.cpp
//  TerminalExtraction
//
//  Created by  Developer on 16.11.12.
//
//

#include "USQliteConnector.h"
#include "sqlite3.h"

using namespace std;

namespace Utils
{
    
    USQliteConnector::USQliteConnector(string dbname)
    {
        sqlite3_open(dbname.c_str(), &_dbconnector);
    }
    
    USQliteConnector::~USQliteConnector()
    {
        if(!_closed)
            Close();
    }
    
    void  USQliteConnector::executeNonQuery(string query, void* errorCallback)
    {
    }
       
    USQLiteResultSet* USQliteConnector::executeSelect(string query, void* errorCallback)
    {
        return nullptr;
    }
    
    int USQliteConnector::executeInsert(string query, void* errorCallback)
    {
        return 0;
    }
        
    void USQliteConnector::Close()
    {
        if(_closed)
            return;
    }
    
}