// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// content::LoadInventory::vfunc_3 @ 0x00266280
struct Node;

class Matcher {
public:
    virtual int Matches(Node *node);     // slot 0
};

struct Container;

struct NodeIter {
    char data[0x18];
    void FUN_00231160(Container *c);
    Node *FUN_00231180(int a, int b);
    Node *FUN_00231230();
};

class Resolver_266280 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Node *Resolve(Matcher *m, int a, int b);     // slot 3
};

class LoadInventory {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Node *vfunc_3(Matcher *matcher, int a, int b);
    char pad04[8];
    Container *container;    // 0x0c
    Resolver_266280 *fallback;      // 0x10
};

Node *LoadInventory::vfunc_3(Matcher *matcher, int a, int b) {
    if (a == 0 && b == 0)
        return 0;
    NodeIter it;
    it.FUN_00231160(container);
    Node *node = it.FUN_00231180(a, b);
    while (node != 0) {
        if (matcher->Matches(node))
            return node;
        node = it.FUN_00231230();
    }
    if (fallback != 0)
        return fallback->Resolve(matcher, a, b);
    return 0;
}
