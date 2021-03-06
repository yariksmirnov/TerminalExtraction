//
//  PivotObject.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/31/12.
//
//

#include "PivotObject.h"
#include "RenderMatrixController.h"
#include "RenderObject.h"
#include "ObjectBehaviourModel.h"
#include "Material.h"
#include "Geometry.h"

PivotObject::PivotObject(ObjectBehaviourModel *behaviourModel) {
    _objectBehaviourModel = behaviourModel;
    _unloaded = false;
    _materialType = PivotMaterialType_Stone;
    _transformMatrix = GLKMatrix4Identity;
    _renderMatrix = GLKMatrix4Identity;
    _needBulletCast = false;
    _needCalcAcxis = false;
    _needMouseCast = false;
    objectConstrAxis = GLKVector3Make(0, 1, 0);
    _isOnScreen = false;
    _editorAspect = nullptr;
    moved = false;
}

void PivotObject::Update() {
    _transformMatrix = _objectBehaviourModel->GetGlobalPosition();
//    if (moved)
//        raycastaspect.boundingShape.Update(transform);
}

void PivotObject::SetGlobalPosition(GLKMatrix4 globalPosition, void *aditionalData, PivotObject *parent, bool afterUpdate)
{
    _objectBehaviourModel->SetGlobalPosition(globalPosition, aditionalData, parent, afterUpdate);
    moved = true;
    if (afterUpdate)
    {
        _objectBehaviourModel->EndFrame();
        Update();
    }
//    else
//    {
//        _transformMatrix = _objectBehaviourModel->GetGlobalPosition();
//    }
}

void PivotObject::AfterUpdate()
{
    if (_isOnScreen)
    {
        if (matrixController)
            _renderMatrix = matrixController->GetRenderMatrix(this);
        else
            _renderMatrix = _transformMatrix;
    }
}

void PivotObject::SetIsOnScreen(bool isOnScreen) {
    _isOnScreen = isOnScreen;
}

shared_ptr<EditorData> PivotObject::GetEditorAspect() {
    return _editorAspect;
}

void PivotObject::BeginFrame() {
    moved = false;
    _objectBehaviourModel->BeginFrame();
    SetIsOnScreen(false);
}

void PivotObject::Frame(double time) {
    _objectBehaviourModel->Frame(time);
}

void PivotObject::EndFrame() {
    _objectBehaviourModel->EndFrame();
    moved = _objectBehaviourModel->moved;
    _transformMatrix = _objectBehaviourModel->GetGlobalPosition();
}

ObjectBehaviourModel * PivotObject::GetObjectBehaviourModel() {
    return _objectBehaviourModel;
}

RenderObject * PivotObject::GetRenderAspect() {
    return NULL;
}

Material * PivotObject::GetMaterial() {
    return NULL;
}

GLKMatrix4 PivotObject::GetRenderMatrix() {
    return _renderMatrix;
}

GLKMatrix4 PivotObject::GetTransformMatrix() {
    return _transformMatrix;
}

GLKVector3 PivotObject::GetPosition() {
    return GLKMatrix4GetTranslation(_transformMatrix);
}

void PivotObject::SetPosition(const GLKVector3& position) {
    _objectBehaviourModel->SetPosition(GLKMatrix4MakeTranslationV(position));
}

PivotObject::~PivotObject() {
    delete _objectBehaviourModel;
}