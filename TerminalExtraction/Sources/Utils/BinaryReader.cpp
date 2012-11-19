//
//  BinaryReader.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/19/12.
//
//

#include "BinaryReader.h"
#include "FileManger.h"


BinaryReader::BinaryReader(std::string filename) {
    FileManager *fm = FileManager::CreateManager();
    std::string path = fm->GetFilePath(filename);
    
    _file = std::ifstream(filename.c_str() , ios_base::in | ios_base::binary );
}