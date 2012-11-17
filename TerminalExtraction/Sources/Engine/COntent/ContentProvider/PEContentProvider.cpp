//
//  PEContentProvider.cpp
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#include "PEContentProvider.h"
#include "FileManger.h"

PEContentProvider::PEContentProvider()
{
    FileManager* fm = FileManager::CreateManager();
    const char *dbName = fm->GetFilePath("Descriptions.sqlite");
    
    _database = new Kompex::SQLiteDatabase(dbName, SQLITE_OPEN_READONLY, NULL);
    
    
    delete fm;
}

PEContentProvider::~PEContentProvider()
{
    delete _database;
}

