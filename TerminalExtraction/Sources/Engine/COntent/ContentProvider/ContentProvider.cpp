//
//  PEContentProvider.cpp
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#include "ContentProvider.h"
#include "FileManger.h"
#include "PackContentHeader.h"
#include "Pack.h"
#include "PackList.h"
#include "CollisionMesh.h"

ContentProvider::ContentProvider()
{
    FileManager* fm = FileManager::CreateManager();
    const char *dbName = fm->GetFilePath("Descriptions.sqlite");
    
    _database = new SQLiteDatabase(dbName, SQLITE_OPEN_READONLY, NULL);
    
    
    
    PackList* p = PackList::SharedInstance();
    
    shared_ptr<PackContentHeader> pch = p->FindObject("WoodenCrate10CollisionMesh");
    if(pch)
    {
        CollisionMesh* cm = new CollisionMesh();
        char* buffer = (char*)malloc(pch->_size);
        pch->_pack->ReadObjectFromPack(buffer, pch);
        cm->LoadFromBuffer(buffer, pch->_size);
        free(buffer);
        delete cm;
    }
    
    delete fm;
}

ContentProvider::~ContentProvider()
{
    delete _database;
}

