// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 24/24)
// fight::FightNodeParentCondition::vfunc_6 @ 0x00235b50
struct Node {
    char pad00[0x14];
    Node *parent;           // 0x14
};

struct NodeRef {
    Node *node;
};

class FightNodeParentCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a1, int a2, int a3);
    virtual NodeRef *vfunc_7(int a2);
    char pad04[8];
    int mode;               // 0x0c
    Node *target;           // 0x10
    char pad14[8];
    char searchAncestors;   // 0x1c
};

bool FightNodeParentCondition::vfunc_6(int a1, int a2, int a3)
{
    NodeRef *ref = vfunc_7(a2);
    if (ref == 0)
        return false;

    Node *parent = ref->node;
    if (parent != 0)
        parent = parent->parent;

    if (searchAncestors) {
        for (; parent != 0; parent = parent->parent) {
            if (parent == target)
                return mode == 0;
        }
        return mode == 1;
    }

    switch (mode) {
    case 0:
        return parent == target;
    case 1:
        return parent != target;
    }
    return false;
}
