// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00231980..0x00231e00 (kind game, layer engine, confidence high), dominant class fight::Node
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x00231d40 fight::Node::vfunc_2 (46 B): matches/0x00231d40.cpp [isolated: conflict: Node; on include/gen/ and not mergeable]
// sym: ?vfunc_2@Node@@UAEPAV1@E@Z
#include "gen/fight.h"
extern "C" char DAT_00427688[];
class Part_231d40 {
  public:
    void init();
};
class Node {
  public:
    virtual void f0();
    virtual void f1();
    virtual Node* vfunc_2(unsigned char);
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    char pad[0x28 - 4];
};
extern void third(Node*);
Node* Node::vfunc_2(unsigned char p) {
    *(void**)this = (void*)((hulk_intptr)DAT_00427688);
    ((Part_231d40*)((char*)this + 0x28))->init();
    ((fight::Branch *)this)->FUN_00233970();
    if (p & 1)
        third(this);
    return this;
}

