// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00234090..0x002343b0 (kind game, layer engine, confidence high), dominant class fight::Param
// (tree_prelude.h: not needed)


// 0x00234270 fight::Param::vfunc_1 (49 B): matches/0x00234270.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?vfunc_1@Param@fight@@UAE_NPAX@Z
#include "gen/fight.h"

class Item_234270 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void apply(fight::Param*, void*);
};

bool fight::Param::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    int i = 0;
    Item_234270* p;
    while ((p = (Item_234270*)vfunc_0(i)) != 0) {
        p->apply(this, arg);
        ++i;
    }
    return true;
}

