// STATUS: equivalent (tools/equiv.py level 3: 2473 inputs, branch coverage 16/16)
// FUN_00306300 @ 0x00306300
// 0x00306300: if the owner is active, run the handler for this node's kind, then do the same for every child
struct Owner_306300 {
    char pad00[0x50];
    char active;
};

class Node;
struct ChildList_306300 {
    Node** begin;
    Node** end;
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int Kind();
    char pad04[0xc];
    Owner_306300* owner;
    ChildList_306300* children;
    char pad18;
    char started;
    void FUN_002f32b0();
    void FUN_002fbf20();
    void FUN_0030e8a0();
    void FUN_00306300();
};

void Node::FUN_00306300()
{
    if (owner == 0 || owner->active == 0)
        return;
    started = 1;
    switch (Kind()) {
    case 2:
        FUN_002f32b0();
        break;
    case 5:
        FUN_002fbf20();
        break;
    case 8:
        FUN_0030e8a0();
        break;
    }
    if (children == 0)
        return;
    for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); i++)
        children->begin[i]->FUN_00306300();
}
