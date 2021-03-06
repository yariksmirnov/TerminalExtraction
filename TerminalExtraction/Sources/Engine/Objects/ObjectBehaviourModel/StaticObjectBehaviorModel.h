//
//  StaticObjectBehaviorModel.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/3/12.
//
//

#ifndef __TerminalExtraction__StaticObjectBehaviorModel__
#define __TerminalExtraction__StaticObjectBehaviorModel__

#include <iostream>
#include "ObjectBehaviourModel.h"

class StaticObjectBehaviourModel : public ObjectBehaviourModel  {
    virtual void SetGlobalPosition(GLKMatrix4 globalPosition, void * aditionalData, PivotObject *parent, bool afterUpdate);
};


#endif /* defined(__TerminalExtraction__StaticObjectBehaviorModel__) */
