//
//  TextureCache.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/4/12.
//
//

#ifndef __TerminalExtraction__TextureCache__
#define __TerminalExtraction__TextureCache__

#include <iostream>
#include <unordered_map>
#include <vector>

class TextureCacheAsyncObserver;

using namespace std;

class FileManager;
class Texture;
class UContainer;

class TextureCache {
    
    static TextureCache             *_sharedCache;
    
    unordered_map<string, Texture>   *_textureMap;
    vector<Texture>                  *_toRemove;
    
    vector<Texture>                  *_needLoad;
    
    TextureCacheAsyncObserver       *_observer;
    
public:
    
    static TextureCache * GetInstance();
    
    int Count();
    
    Texture * CreateTexture(string filename);
    void CreateTextureAsync(TextureCacheAsyncObserver *observer);
    
    void RemoveObserver(TextureCacheAsyncObserver *observer);
    void Update();
    
};

#endif /* defined(__TerminalExtraction__TextureCache__) */
