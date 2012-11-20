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



class MeshContentadditionalheader {
    
    
public:
    int _ismaxdetalized;
    int _isstatic;
    int _skinsize;
    
    
    MeshContentadditionalheader(BinaryReader* inputStream, int type);
};

class PackContetnHeader {
    
    
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
    void* _engineObject;
    //readed content object
    void* _contentObject;
    //number in pack
    int _number;
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
    MeshContentadditionalheader* _mh;
    int _disposeCount;
    
    PackContetnHeader(BinaryReader* inputStream, int index);
    ~PackContetnHeader();
    
};

#endif /* defined(__TerminalExtraction__PackContentHeader__) */
