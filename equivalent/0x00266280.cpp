// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 11/12, incomplete)
// content::LoadInventory::vfunc_3 @ 0x00266280
#include "compat/ptr.h"
#include "gen/content.h"

struct Node_266280;

class Matcher {
public:
    virtual int Matches(Node_266280 *node);     // slot 0
};

struct Container;

struct NodeIter {
    char data[0x18];
    void FUN_00231160(Container *c);
    Node_266280 *FUN_00231180(int a, int b);
    Node_266280 *FUN_00231230();
};

class Resolver_266280 {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual Node_266280 *Resolve(Matcher *m, int a, int b);     // slot 3
};

void* content::LoadInventory::vfunc_3(hulk_intptr __p0, int a, int b) { Matcher * matcher = (Matcher *)__p0;

    if (a == 0 && b == 0)
        return (void*)(0);
    NodeIter it;
    it.FUN_00231160((*(Container * *)&this->f_0c));
    Node_266280 *node = it.FUN_00231180(a, b);
    while (node != 0) {
        if (matcher->Matches(node))
            return (void*)(node);
        node = it.FUN_00231230();
    }
    if ((*(Resolver_266280 * *)&this->f_10) != 0)
        return (void*)((*(Resolver_266280 * *)&this->f_10)->Resolve(matcher, a, b));
    return (void*)(0);
}
