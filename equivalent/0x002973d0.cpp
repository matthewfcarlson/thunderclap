// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_002973d0 @ 0x002973d0
struct Matrix {
    float m[16];
};

class Child;
namespace pure3d {
namespace scenegraph {

class TransformNode;

// equiv-map: ??0BranchNode@scenegraph@pure3d@@QAE@ABV012@@Z = 0x002971f0
class BranchNode {
public:
    BranchNode(const BranchNode &source) throw();
    virtual void v0();
    virtual void v1();
    char pad04[0x24];
};

class Child {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual Child *Clone();
    void FUN_002a77c0(TransformNode *parent);
};

class TransformNode : public BranchNode {
public:
    Matrix local;
    Matrix world;
    Child *child;
    TransformNode(const TransformNode &source) throw();
    virtual void v0();
};

TransformNode::TransformNode(const TransformNode &source) throw() : BranchNode(source)
{
    child = 0;
    local = source.local;
    world = source.world;
    if (source.child != 0) {
        Child *clone = source.child->Clone();
        if (clone != 0)
            clone->AddRef();
        if (child != 0)
            child->Release();
        child = clone;
        if (clone != 0)
            clone->FUN_002a77c0(this);
    }
}

}
}
