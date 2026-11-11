// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0014ea20..0x0014ed50 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0014ecb0 hulkfight::motion::CollisionExplosionCondition::vfunc_6 (74 B): matches/0x0014ecb0.cpp [isolated: on include/gen/, and its TU merges more functions without the headers; on include/gen/ and not mergeable]
// sym: ?vfunc_6@CollisionExplosionCondition@motion@hulkfight@@UAE_NPAX00@Z
#include "gen/hulkfight.h"

extern "C" char DAT_00494b44[];
extern "C" char DAT_00494b60[];
int FUN_00344e74(void*, int, const void*, const void*, int);
struct V {
    virtual char a();
    virtual char b();
    virtual char c();
    virtual unsigned char* d();
};

bool hulkfight::motion::CollisionExplosionCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * param = (void *)__p1; void * extra = (void *)__p2;

    int r = FUN_00344e74(param, 0, (const void*)((hulk_intptr)DAT_00494b44), (const void*)((hulk_intptr)DAT_00494b60), 0);
    if (r == 0)
        return (bool)(0);
    unsigned char* x = ((V*)param)->d();
    if (x == 0)
        return (bool)(0);
    return (bool)(this->f_0c == x[0x90] ? 1 : 0);
}

