//
//  EditorData.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/1/12.
//
//

#include "EditorData.h"
#include "IdGenerator.h"

EditorData::EditorData(string descrName, int type) {
    _descriptiongName = descrName;
    _objectType = type;
    _objectId = IdGenerator::DefaultGenerator()->GenerateId();
}