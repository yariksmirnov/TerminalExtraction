//
//  UnAnimRenderObject.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#include "UnAnimRenderObject.h"
#include "EngineMesh.h"
#include "Material.h"
#include "TEEngine.h"

UnAnimRenderObject::UnAnimRenderObject(const EngineMesh *mesh):RenderObject() {
    _mesh = mesh;
    shared_ptr<EngineMesh> m(new EngineMesh());
}

void UnAnimRenderObject::Render(int lod, Material *material) {
    material->ApplyLod(lod, engine->GetShader());
    _mesh->Bind();
    _mesh->Render();
    _mesh->Unbind();
}

UnAnimRenderObject::~UnAnimRenderObject() {
    delete _mesh;
}