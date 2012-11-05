//
//  TextureCacheAsyncDelegate.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/4/12.
//
//

#ifndef __TerminalExtraction__TextureCacheAsyncDelegate__
#define __TerminalExtraction__TextureCacheAsyncDelegate__

#include <iostream>

using namespace std;

class Texture;

class TextureCacheAsyncObserver {
public:
    
    string GetTextureFileName();
    
    void OnTextureLoaded(Texture *texture);
};

#endif /* defined(__TerminalExtraction__TextureCacheAsyncDelegate__) */
