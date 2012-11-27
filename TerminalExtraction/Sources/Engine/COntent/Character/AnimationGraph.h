//
//  AnimationGraph.h
//  TerminalExtraction
//
//  Created by Anton Katekov on 27.11.12.
//
//

#ifndef __TerminalExtraction__AnimationGraph__
#define __TerminalExtraction__AnimationGraph__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BinaryReader;
class NodeEvent;
class Animation;

class AnimationNode {
    string              _name;
    int                 _index;
    
    vector<shared_ptr<NodeEvent>>          _nodeEvents; // исходящие рёбра
    Animation          *_animation;                     // соответствующая узлу анимация
    
public:
    
    float               _animationSpeed = 0.075f;       // скорость анимации
    float               _animTime;                      // длина анимации
    bool                _isOneTime;                     // одноразовая или нет
    
    string              GetName() const { return _name; };
    int                 GetIndex() const { return _index; };
    Animation*          GetAnimation() const { return _animation; };
    void                SetAnimation(Animation* animation) { _animation = animation; };
    
    AnimationNode(string name, int index);
    ~AnimationNode();
    
    void                                AddNodeEvent(shared_ptr<NodeEvent> event);
    shared_ptr<AnimationNode>           Advance(string event);
    
    static shared_ptr<AnimationNode>    AnimationNodeFromStream(BinaryReader *br);
    
};

class NodeEvent {
    string              _neededEvent;                   // необходимое событие
    string              _description;                   // описание
    
    string              _parentName;                    // имя парента
    string              _associatedName;                // имя чилда
    
    shared_ptr<AnimationNode>      _parentNode;                    // ссылка на владельца
    shared_ptr<AnimationNode>      _associatedNode;                // узел к которому ведет событие
    
public:
    string              GetNeededEvent() const { return _neededEvent; };
    string              GetDescription() const { return _description; };
    
    shared_ptr<AnimationNode>      GetParentNode() const { return _parentNode; };
    shared_ptr<AnimationNode>      GetAssociatedNode() const { return _associatedNode; };
    
    void                SetParentNode(shared_ptr<AnimationNode> parentNode) {  _parentNode = parentNode; };
    void                SetAssociatedNode(shared_ptr<AnimationNode> associatedNode) { _associatedNode = associatedNode; };
    
    inline string              GetParentName() const;
    inline string              GetAssociatedNodeName() const;
    
    NodeEvent(string neededevent, string description, string parentName, string associatedName);
    ~NodeEvent();
    
    static shared_ptr<NodeEvent>  NodeEventFromStream(BinaryReader *br);
};

class AnimationGraph {
};

inline string NodeEvent::GetParentName() const
{
    return _parentNode->GetName();
}

inline string NodeEvent::GetAssociatedNodeName() const
{
    return _associatedNode->GetName();
}

#endif /* defined(__TerminalExtraction__AnimationGraph__) */
