// STATUS: equivalent (tools/equiv.py level 3: 2424 inputs, branch coverage 14/14)
// pure3d::scenegraph::BranchNode::vfunc_10 @ 0x002966a0
namespace pure3d {
namespace scenegraph {

class Node {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void vfunc_10(int a, unsigned int mask, int mode, int d);
};

class BranchNode : public Node {
public:
    virtual void vfunc_10(int a, unsigned int mask, int mode, int d);
    char pad04[0x10 - 4];
    unsigned int flags;
    char pad14[4];
    unsigned int childCount;
    Node **children;
};

void BranchNode::vfunc_10(int a, unsigned int mask, int mode, int d)
{
    if (mode == 2) {
        bool skip;
        if ((unsigned char)a == 1) {
            if ((unsigned char)d == 1)
                skip = (flags & mask) == mask;
            else
                skip = false;
        } else {
            skip = (unsigned char)d == 1 && (flags & mask) == 0;
        }
        if (skip)
            return;
        for (unsigned int i = 0; i < childCount; i++)
            children[i]->vfunc_10(a, mask, 2, d);
    }
    Node::vfunc_10(a, mask, mode, d);
}

}
}
