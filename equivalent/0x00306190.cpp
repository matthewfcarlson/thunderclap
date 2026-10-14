// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 20/20)
// FUN_00306190 @ 0x00306190
struct NodeList;

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int Kind();
    char pad04[4];
    int id;                     // 8
    char pad0c[8];
    NodeList *children;         // 0x14
    Node *FUN_00306190(int wanted, bool strict);
};

struct NodeList {
    Node **begin;
    Node **end;
};

// Finds the node with the wanted id in this subtree (kind 1 nodes only count when not strict).
Node *Node::FUN_00306190(int wanted, bool strict)
{
    if (id > wanted)
        return 0;
    if (Kind() != 1 || !strict) {
        if (id == wanted)
            return this;
    }
    if (children == 0)
        return 0;
    for (unsigned int i = 0; i < (unsigned int)(children->end - children->begin); i++) {
        Node *child = children->begin[i];
        if (child->id == wanted && child->Kind() != 1)
            return child;
        Node *found = child->FUN_00306190(wanted, strict);
        if (found != 0)
            return found;
    }
    return 0;
}
