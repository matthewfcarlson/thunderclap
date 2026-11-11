// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e4330..0x000e8490 (kind game, layer game, confidence high), dominant class FEThingsBase
// (tree_prelude.h: not needed)


// 0x000e4f70 FEScreenBase::vfunc_22 (68 B): matches/0x000e4f70.cpp [isolated: compile error C2440: 'initializing' : cannot convert from 'int' to 'void *'; on include/gen/ and not mergeable]
// sym: ?vfunc_22@FEScreenBase@@UAEHH@Z
// Same code shape as 0x000e49f0 (propagated; names are from that function)
#include "gen/global.h"

extern void* __cdecl FUN_0008d690(unsigned int);
struct VScroll_nv_e4f70 {
    int make(void*, unsigned int);
};

int FEScreenBase::vfunc_22(int param) {
    void* p = FUN_0008d690(0x270);
    int r;
    if (p)
        r = ((VScroll_nv_e4f70*)(((VScroll*)(((VScroll*)p)))))->make(this, param);
    else
        r = 0;
    vfunc_21(r);
    return r;
}

