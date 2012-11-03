//
//  PivotObject.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 10/31/12.
//
//

#ifndef __TerminalExtraction__PivotObject__
#define __TerminalExtraction__PivotObject__

#include <iostream>
#include "TranslateableObject.h"

class EditorData;
class ObjectBehaviourModel;
class RenderMatrixController;
class RenderObject;
class Material;

enum {
    PivotMaterialType_Stone,
    PivotMaterialType_Metal,
    PivotMaterialType_Wood,
    PivotMaterialType_DynamicMetal,
    PivotMaterialType_DynamicWood,
    PivotMaterialType_DynamicAtone,
    PivotMaterialType_DynamicAlive,
    PivotMaterialType_DynamicAlien
};
typedef unsigned int PivotMaterialType;

class PivotObject : public TranslateableObject {
    GLKMatrix4              _renderMatrix;
    GLKMatrix4              _transformMatrix;
    
    ObjectBehaviourModel    *_objectBehaviourModel;
    
    bool                _unloaded;
    
    int                 _materialType;
    
    bool                _needMouseCast;
    bool                _needBulletCast;
    bool                _needCalcAcxis;
    
    bool                _isOnScreen;
    
public:
    
    GLKVector3 objectConstrAxis;
    GLKVector3 objectConstrForward;
    
    EditorData *editorAspect;
    
    RenderMatrixController      *matrixController;
    
    bool        moved;
    
    
    PivotObject(ObjectBehaviourModel *behaviourModel);
    ~PivotObject();

    GLKMatrix3 GetRenderMatrix();
    GLKMatrix4 GetTransformMatrix();
    
    ObjectBehaviourModel *GetObjectBehaviourModel();
    
    void Update();
    void AfterUpdate();
    void Frame(double time);
    void BeginFrame();
    void EndFrame();
    
    void SetIsOnScreen(bool isOnScreen);
    
    void SetGlobalPosition(GLKMatrix4 globalPosition, void * aditionalData, PivotObject *parent, bool afterUpdate);
    
    virtual RenderObject * GetRenderAspect();
    virtual Material * GetMaterial();
    
    virtual GLKVector3 GetPosition();
    virtual void SetPosition(GLKVector3 position);
    
};

#endif /* defined(__TerminalExtraction__PivotObject__) */
