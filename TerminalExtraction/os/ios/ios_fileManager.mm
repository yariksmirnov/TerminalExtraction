//
//  ios_fileManager.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "ios_fileManager.h"


string* iosFileManager::GetContent(string filename) {
    
    size_t dotPosition = filename.find(".");
    string extension = filename.substr(dotPosition + 1);
    NSString* pureName = [[NSString stringWithUTF8String:filename.c_str()] substringToIndex:dotPosition];
    
    NSString *filePath = [[NSBundle mainBundle] pathForResource:pureName ofType:[NSString stringWithUTF8String:extension.c_str()]];
    
    NSString *content = [NSString stringWithContentsOfFile:filePath encoding:NSUTF8StringEncoding error:NULL];
    
    const char * cContent = [content UTF8String];
    int len = [content length];
 
    return new string(cContent, len);
    
}