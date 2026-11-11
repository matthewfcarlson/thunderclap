// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ee9b0..0x000f0f70 (kind game, layer game, confidence high), dominant class FEThingsBase
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x000efeb0 FEThingsBase::vfunc_59 (39 B): matches/0x000efeb0.cpp [isolated: conflict: lookup; on include/gen/ and not mergeable]
// sym: ?vfunc_59@FEThingsBase@@UAEHH@Z
#include "gen/global.h"

extern "C" int __cdecl lookup(int);
struct MenuSelector_nv_efeb0 {
    int call(int, int);
};

int FEThingsBase::vfunc_59(int arg) {
    hulk_intptr p = lookup(0x3db0);
    if (p)
        return ((MenuSelector_nv_efeb0*)(((MenuSelector*)(((MenuSelector*)p)))))->call(arg, 0);
    return 0;
}

