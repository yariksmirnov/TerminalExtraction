//
//  USQliteConnector.h
//  TerminalExtraction
//
//  Created by  Developer on 16.11.12.
//
//

#ifndef __TerminalExtraction__USQliteConnector__
#define __TerminalExtraction__USQliteConnector__

#include <iostream>
#include <string>

struct sqlite3;
class USQLiteResultSet;

using namespace std;

namespace Utils {

    class SQliteConnector
    {
        sqlite3* _dbconnector;
        
        bool _closed;
    public:
        
        bool IsClosed() const {return _closed;}
        
        SQliteConnector(string dbname);
        ~SQliteConnector();
        
        /// <summary>
        /// executes simple query like update
        /// </summary>
        /// <param name="query"></param>
        /// <param name="errorAct"></param>
        void executeNonQuery(string query, void *errorCallback);
        
        /// <summary>
        /// executes select query, returns selection result
        /// </summary>
        /// <param name="query"> select statement</param>
        /// <param name="errorAct">executes if error in statement are detected</param>
        /// <returns>SQliteResultSet with result of selection</returns>
        USQLiteResultSet* executeSelect(string query, void *errorCallback);
        
        /// <summary>
        /// executes insert query, returns id of last inserted row
        /// </summary>
        /// <param name="query">insert statement</param>
        /// <param name="errorAct">executes if error in statement are detected</param>
        /// <returns>id of last inserted row</returns>
        int executeInsert(string query, void *errorCallback);
        
        /// <summary>
        /// close the connection
        /// </summary>
        void Close();
        
    };
}

#endif /* defined(__TerminalExtraction__USQliteConnector__) */
