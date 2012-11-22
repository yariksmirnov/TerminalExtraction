//
//  PackContentHeader.h
//  TerminalExtraction
//
//  Created by Yarik Smirnov on 11/20/12.
//
//

#ifndef __TerminalExtraction__PackContentHeader__
#define __TerminalExtraction__PackContentHeader__

#include <iostream>
#include <string>

using namespace std;

class BinaryReader;
class PackObjectInterface;

//urgly rudiment
class MeshContentAdditionalHeader {
public:
    int _ismaxdetalized;
    int _isstatic;
    int _skinsize;
    
    MeshContentAdditionalHeader(BinaryReader* inputStream, int type);
};

class PackContentHeader {
public:
    enum
    {
        MissingObject = -1,
        MeshOptimazedForStore = 0,
        MeshOptimazedForLoading = 1,
        PNGTexture = 2,
        
        
        MeshList = 10,
        LevelObjectDescription = 12,
        GameObjectDescription = 13,
        RenderObjectDescription = 14,
        ParticelRenderObjectDescription = 15,
        
        
        CollisionMesh = 20,
        ConvexMesh = 21,
        
        Skeleton = 30,
        SkeletonWithAddInfo = 31,
        BaseAnimation = 40,
        Character = 50,
        TextureList = 60,
        Material = 61,
    };
    
    //count of engine object created from this contetnt object
    int _userCount;
    //sample engine object
    shared_ptr<PackObjectInterface> _engineObject;
    //readed content object
    void* _contentObject;
    //number in pack
    int _index;
    //offset from packs header end
    int _offset;
    //size in pack
    int _size;
    //size of hedaer
    int _headersize;
    //object type
    int _format;
    //name of object
    //id
    std::string _name;
    //additional info for meshes
    MeshContentAdditionalHeader* _mh;
    int _disposeCount;
    
    PackContentHeader(BinaryReader* inputStream, int index);
    ~PackContentHeader();
    
};

#endif /* defined(__TerminalExtraction__PackContentHeader__) */
