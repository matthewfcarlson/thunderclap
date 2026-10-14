// STATUS: equivalent (tools/equiv.py level 3: 94 inputs, branch coverage 12/12)
// pure3d::scenegraph::BranchNode::vfunc_19 @ 0x002967a0
class Node {
public:
    virtual void v0();
    virtual void Release();
};

namespace pure3d {
namespace scenegraph {

class BranchNode {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void vfunc_19(Node* child);
    char pad04[0x14];
    unsigned int count;    // 0x18
    Node** children;       // 0x1c
};

void BranchNode::vfunc_19(Node* child)
{
    int i = (int)count - 1;
    if (i < 0)
        return;
    Node** list = children;
    while (list[i] != child) {
        i--;
        if (i < 0)
            return;
    }
    if (list[i] != 0) {
        list[i]->Release();
        list[i] = 0;
    }
    for (unsigned int j = i + 1; j < count; j++) {
        children[j - 1] = children[j];
        children[j] = 0;
    }
    count--;
}

}
}
