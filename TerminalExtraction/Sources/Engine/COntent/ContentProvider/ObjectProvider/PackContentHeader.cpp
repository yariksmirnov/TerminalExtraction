//
//  PackContentHeader.cpp
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/20/12.
//
//

#include "PackContentHeader.h"
#include "BinaryReader.h"

MeshContentadditionalheader::MeshContentadditionalheader(BinaryReader* inputStream, int type)
{
    switch (type)
    {
        case PackContentHeader::MeshOptimazedForStore:
        {
            _ismaxdetalized = inputStream->ReadInt();
            _skinsize = inputStream->ReadInt();
            int lodcount = inputStream->ReadInt();
            for (int j = 0; j < lodcount; j++)
                inputStream->ReadString();
        } break;
        case PackContentHeader::MeshOptimazedForLoading:
        {
            _ismaxdetalized = inputStream->ReadInt();
            _isstatic = inputStream->ReadInt();
            int lodcount = inputStream->ReadInt();
            for (int j = 0; j < lodcount; j++)
                inputStream->ReadString();
        } break;
        default:
        { } break;
    }
}

PackContentHeader::PackContentHeader(BinaryReader* inputStream, int index)
{
    _userCount = 0;
    _number = index;
    
    _name = inputStream->ReadString();
    _offset = inputStream->ReadInt();
    _format = inputStream->ReadInt();
    _headersize = inputStream->ReadInt();
    
    //когдато я был молодой и глупый и теперь пишу этот кастыль
    if (_format == PackContentHeader::MeshOptimazedForLoading || _format == PackContentHeader::MeshOptimazedForStore)
    {
        _mh = new MeshContentadditionalheader(inputStream, _format);
    }
    else
    {
        _size = inputStream->ReadInt();
    }
    
    
}

PackContentHeader::~PackContentHeader()
{
    if(_mh)
        delete _mh;
}