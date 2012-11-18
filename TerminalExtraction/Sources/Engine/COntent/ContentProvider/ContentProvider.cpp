//
//  PEContentProvider.cpp
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#include "ContentProvider.h"
#include "FileManger.h"

ContentProvider::ContentProvider()
{
    FileManager* fm = FileManager::CreateManager();
    const char *dbName = fm->GetFilePath("Descriptions.sqlite");
    
    _database = new SQLiteDatabase(dbName, SQLITE_OPEN_READONLY, NULL);
    
    delete fm;
}

ContentProvider::~ContentProvider()
{
    delete _database;
}

