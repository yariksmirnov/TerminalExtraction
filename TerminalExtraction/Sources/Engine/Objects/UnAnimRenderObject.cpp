//
//  UnAnimRenderObject.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "UnAnimRenderObject.h"
#include "EngineMesh.h"

UnAnimRenderObject::UnAnimRenderObject(const EngineMesh *mesh) {
    _mesh = mesh;
}

void UnAnimRenderObject::Render(int lod, Material *material) {
    _mesh->Bind();
    _mesh->Render();
}