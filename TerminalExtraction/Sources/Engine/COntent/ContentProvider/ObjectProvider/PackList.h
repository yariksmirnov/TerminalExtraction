//
//  PEPackList.h
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#ifndef __TerminalExtraction__PEPackList__
#define __TerminalExtraction__PEPackList__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class PackContentHeader;
class Pack;

class PackList {
    vector<shared_ptr<Pack>> _packs;
public:
    PackList();
    ~PackList();
    
    shared_ptr<PackContentHeader> FindObject(string name);
    
    
    static PackList* SharedInstance();
};

#endif /* defined(__TerminalExtraction__PEPackList__) */
