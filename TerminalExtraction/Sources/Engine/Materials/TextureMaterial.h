//
//  TextureMaterial.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#ifndef __TerminalExtraction__TextureMaterial__
#define __TerminalExtraction__TextureMaterial__

#include <iostream>
#include "Material.h"

using namespace std;

class Texture;
class Shader;

class TextureMaterial : public Material {
    Texture     *_texture;

public:
    
    TextureMaterial(string name);
    
    void ApplyLod(int lod, Shader *shader);
    
    Texture *GetTexture();
};

#endif /* defined(__TerminalExtraction__TextureMaterial__) */
