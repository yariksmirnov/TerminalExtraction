//
//  FileManger.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "FileManger.h"
#include "ios_fileManager.h"

FileManager * FileManager::CreateManager() {
    return new iosFileManager();
}

string* FileManager::GetContent(string filename) {
    return new string("");
}