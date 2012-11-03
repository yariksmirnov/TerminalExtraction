//
//  ios_fileManager.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "ios_fileManager.h"


string iosFileManager::GetContent(string filename) {
    
    size_t dotPosition = filename.find_last_not_of(".");
    string extension = filename.substr(dotPosition);
    
    NSString *filePath = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:filename.c_str()] ofType:[NSString stringWithUTF8String:extension.c_str()]];
    
    NSString *content = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:NULL];
    
    const char * cContent = [content UTF8String];
    int len = [content length];
    
    return string(cContent, len);
    
}