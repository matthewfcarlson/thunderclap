// STATUS: equivalent (tools/equiv.py level 3: 2985 inputs, branch coverage 6/6)
// pure3d::scenegraph::BranchNode::vfunc_6 @ 0x002965a0
namespace pure3d { namespace scenegraph {
struct Node {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6(void*, void*);
};
struct BranchNode : Node {
    char padding[20];
    unsigned int count;
    Node** children;
    void vfunc_6(void* a, void* b);
};
void BranchNode::vfunc_6(void* a, void* b) {
    if (!(padding[12] & 1)) {
        for (unsigned int i = 0; i < count; ++i)
            children[i]->vfunc_6(a,b);
    }
}
}}