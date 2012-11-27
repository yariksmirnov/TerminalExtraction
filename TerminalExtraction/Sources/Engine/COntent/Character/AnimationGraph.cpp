//
//  AnimationGraph.cpp
//  TerminalExtraction
//
//  Created by Anton Katekov on 27.11.12.
//
//

#include "AnimationGraph.h"
#include "BinaryReader.h"
#include "Animation.h"
#include "AnimationFull.h"

//public static Dictionary<string, string> FromStream(System.IO.BinaryReader bw)
//{
//    int count = bw.ReadInt32();
//    Dictionary<string, string> result = new Dictionary<string, string>(count);
//    for (int i = 0; i < count; i++)
//    {
//        result.Add(bw.ReadPackString(), bw.ReadPackString());
//    }
//    return result;
//}

AnimationNode::AnimationNode(string name, int index)
{
    _name = name;
    _index = index;
}

AnimationNode::~AnimationNode()
{
    if(_animation)
        delete _animation;
}

void AnimationNode::AddNodeEvent(shared_ptr<NodeEvent> event)
{
    _nodeEvents.push_back(event);
}

shared_ptr<AnimationNode> AnimationNode::Advance(string event)
{
    for (int i = 0; i < _nodeEvents.size(); i++)
    {
        shared_ptr<NodeEvent> node = _nodeEvents.at(i);
        if (node->GetNeededEvent() == event)
            return node->GetAssociatedNode();
    }
    
    return nullptr;
}

shared_ptr<AnimationNode> AnimationNode::AnimationNodeFromStream(BinaryReader *br)
{
    int index = br->ReadInt();
    string name = br->ReadString();
    shared_ptr<AnimationNode> node(new AnimationNode(name, index));
   
    int animType = br->ReadInt();
    Animation* animation;
    switch (animType)
    {
        case 0:
            animation = new AnimationFull();
            break;
        default:
            break;
    }
    //node.SetProperties( DictionaryMethods.FromStream(br));
    {
        
    }
    
    int count = br->ReadInt();
    for (int i = 0; i < count; i++)
        node->AddNodeEvent(shared_ptr<NodeEvent> (NodeEvent::NodeEventFromStream(br)));
    
    return node;
}


NodeEvent::NodeEvent(string neededevent, string description, string parentName, string associatedName)
{
    _neededEvent = neededevent;
    _description = description;
    _parentName = parentName;
    _associatedName = associatedName;
}

NodeEvent::~NodeEvent()
{
    
}

shared_ptr<NodeEvent> NodeEvent::NodeEventFromStream(BinaryReader *br)
{
    string ne = br->ReadString();
    string de = br->ReadString();
    
    string pn = br->ReadString();
    string an = br->ReadString();
    
    shared_ptr<NodeEvent> result(new NodeEvent(ne, de, pn, an));
    return result;
}