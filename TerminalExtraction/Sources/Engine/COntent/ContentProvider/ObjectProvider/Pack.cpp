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
    SysLogInfo("pack name:       %s", filename.c_str());
    this->ReadPack();
    SysLogInfo("pack header size:        %d", _headersize);
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
        
        pch->_pack = this;
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

shared_ptr<PackContentHeader> Pack::FindObject(string name)
{
    for (std::vector<shared_ptr<PackContentHeader>>::iterator i = _objects.begin(); i != _objects.end(); ++i)
    {
        shared_ptr<PackContentHeader> p = *i;
        if (p->_name == name) {
            return p;
        }
    }
    return shared_ptr<PackContentHeader>(nullptr);
}

bool Pack::ReadObjectFromPack(char* buffer, string name)
{
    shared_ptr<PackContentHeader> pch = FindObject(name);
    if (!pch)
        return false;
    
    _reader->SetPosition(_headersize + pch->_offset);
    _reader->ReadBuffer(pch->_size, buffer);
    return true;
}

bool Pack::ReadObjectFromPack(char* buffer, shared_ptr<PackContentHeader> object)
{
    _reader->SetPosition(_headersize + object->_offset);
    _reader->ReadBuffer(object->_size, buffer);
    return true;
}

Pack::~Pack()
{
    delete _reader;
}