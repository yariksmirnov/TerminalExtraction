//
//  PEPack.cpp
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#include "Pack.h"
#include "BinaryReader.h"
#include "Sys.h"

Pack::Pack(std::string filename)
{
    _filename = filename;
    _reader = new BinaryReader(filename);
    this->ReadPack();
}

void Pack::ReadPack()
{
    std::vector<shared_ptr<PackContentHeader>> needcalcsize;
    
    int foratID = _reader->ReadInt();

    if (foratID != 43647457)
    {
        delete _reader;
        return;
    }
    int objectcount = _reader->ReadInt();
    
    for (int i = 0; i < objectcount; i++)
    {
        shared_ptr<PackContentHeader> pch(new PackContentHeader(_reader, i));
        
        if (pch->_size == 0)
            needcalcsize.push_back(pch);
        
        _objects.push_back(pch);
        
    }
    
    _headersize = _reader->GetPosition();
    
    for (int i = 0; i < needcalcsize.size() - 1; i++)
    {
        shared_ptr<PackContentHeader> pch = needcalcsize.at(i);
        int index = pch->_index;
        
        shared_ptr<PackContentHeader> nextpch = _objects.at(index + 1);
        pch->_size = nextpch->_offset - pch->_offset;
    }
    
    if (needcalcsize.at(needcalcsize.size() - 1)->_index + 1 == _objects.size())
    {
        shared_ptr<PackContentHeader> pch = needcalcsize.at(needcalcsize.size() - 1);
        shared_ptr<PackContentHeader> lactpch = _objects.at(_objects.size() - 1);
        pch->_size = _reader->GetLength() - (lactpch->_offset + _headersize);
    }
    else
    {
        shared_ptr<PackContentHeader> pch = needcalcsize.at(needcalcsize.size() - 1);
        shared_ptr<PackContentHeader> next = _objects.at(pch->_index + 1);
        pch->_size = next->_offset - pch->_offset;
    }
}

Pack::~Pack()
{
    delete _reader;
}