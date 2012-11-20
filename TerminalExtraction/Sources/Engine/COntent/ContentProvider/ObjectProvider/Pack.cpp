//
//  PEPack.cpp
//  TerminalExtraction
//
//  Created by Anton Katekov on 17.11.12.
//
//

#include "Pack.h"
#include "BinaryReader.h"

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
        int index = [[needcalcsize objectAtIndex:i] intValue];
        PackContentHeader* pch = [_objects objectAtIndex:index];
        
        PackContentHeader* nextpch = [_objects objectAtIndex:index+1];
        pch.size = nextpch.offset - pch.offset;
    }
    
    if ([[needcalcsize objectAtIndex:needcalcsize.count - 1] intValue] + 1 == _objects.count)
    {
        int index = [[needcalcsize objectAtIndex:needcalcsize.count - 1] intValue];
        PackContentHeader* pch = [_objects objectAtIndex:index];
        PackContentHeader* lactpch = [_objects objectAtIndex:_objects.count - 1];
        pch.size = br.fileSize - (lactpch.offset + _headersize);
    }
    else
    {
        int processingobject = [[needcalcsize objectAtIndex:needcalcsize.count - 1] intValue];
        PackContentHeader* pch = [_objects objectAtIndex:processingobject];
        PackContentHeader* next = [_objects objectAtIndex:processingobject + 1];
        pch.size = next.offset - pch.offset;
    }
    [br Close];
    _reader = [br retain];
}

Pack::~Pack()
{
    delete _reader;
}