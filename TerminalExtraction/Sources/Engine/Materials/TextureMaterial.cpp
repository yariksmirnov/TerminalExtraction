//
//  TextureMaterial.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "TextureMaterial.h"
#include "Shader.h"

TextureMaterial::TextureMaterial(string name) {
    
}

void TextureMaterial::ApplyLod(int lod, Shader *shader) {
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, _texture->name);
//    glUniform1i(shader.shaderuniforms[UNIFORM_COLOR_TEXTURE], 0);
}

Texture * TextureMaterial::GetTexture() {
    return _texture;
}