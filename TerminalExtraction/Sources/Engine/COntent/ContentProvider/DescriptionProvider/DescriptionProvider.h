//
//  PEDescriptionProvider.h
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#ifndef __TerminalExtraction__PEDescriptionProvider__
#define __TerminalExtraction__PEDescriptionProvider__

#include <iostream>
#include <vector>

using namespace std;

class BehaviourModelDescription;
class LevelObjectDescription;

class DescriptionProvider {
    
    
public:
    vector<shared_ptr<BehaviourModelDescription>> behaviourModelDescriptions;
    vector<shared_ptr<LevelObjectDescription>> levelObjectDescriptions;
};

#endif /* defined(__TerminalExtraction__PEDescriptionProvider__) */
