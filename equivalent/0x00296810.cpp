// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::scenegraph::TransformNode::vfunc_6 @ 0x00296810
namespace pure3d { namespace scenegraph {
struct Node {
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(int, int);
};
struct BranchNode : Node { void vfunc_6(int, int); };
struct TransformNode : BranchNode {
    char beforeFlags[0x10 - 4];
    unsigned char flags;
    char beforeChild[0xa8 - 0x11];
    Node* child;
    void vfunc_6(int a, int b);
};
void TransformNode::vfunc_6(int a, int b) {
    if ((flags & 1) == 0) {
        if (child) child->vfunc_6(a, b);
        BranchNode::vfunc_6(a, b);
    }
}
}}
