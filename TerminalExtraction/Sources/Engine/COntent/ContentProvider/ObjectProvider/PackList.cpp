//
//  PEPackList.cpp
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#include "PackList.h"
#include "Pack.h"

PackList* instance = NULL;

PackList* PackList::SharedInstance()
{
    if(!instance)
        instance = new PackList();
    return instance;
}

PackList::PackList()
{
    _packs.push_back(shared_ptr<Pack>(new Pack("Data.pack")));
}

PackList::~PackList()
{}

shared_ptr<PackContentHeader> PackList::FindObject(string name)
{
    for (std::vector<shared_ptr<Pack>>::iterator i = _packs.begin(); i != _packs.end(); ++i) {
        shared_ptr<Pack> p = *i;
        shared_ptr<PackContentHeader> result = p->FindObject(name);
        if (result)
            return result;
    }
    return shared_ptr<PackContentHeader>(nullptr);
}