// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0005a740..0x0005c6b0 (kind game, layer game, confidence high), dominant class CGrappleOpportunityTrack
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0005b4f0 CGrappleIntangibleTrack::vfunc_12 (99 B): matches/0x0005b4f0.cpp [isolated: conflict: FUN_0008d690; on include/gen/ and not mergeable]
// sym: ?vfunc_12@CGrappleIntangibleTrack@@UAEHH@Z
#include "gen/global.h"

struct Obj_5b4f0 {
    char pad[0x104];
    int field;
};
struct ObjB_5b4f0 {
    char pad[0x330];
    Obj_5b4f0* f330;
    Obj_5b4f0* f334;
    Obj_5b4f0* Get() {
        if (f334)
            return f334;
        if (f330)
            return f330;
        return 0;
    }
};
struct ObjA_5b4f0 {
    ObjB_5b4f0* GetB_00059a30();
};
struct Input_5b4f0 {
    ObjA_5b4f0* GetA_000592a0();
};
struct CIntangibleAction_nv_5b4f0 {
    CIntangibleAction* Init_0001f560(int);
};
void* __cdecl FUN_0008d690(int);

hulk_intptr CGrappleIntangibleTrack::vfunc_12(hulk_intptr __p0) { Input_5b4f0 * p = (Input_5b4f0 *)__p0;

    if (p) {
        ObjA_5b4f0* a = p->GetA_000592a0();
        if (a) {
            ObjB_5b4f0* b = a->GetB_00059a30();
            if (b) {
                Obj_5b4f0* x = b->Get();
                if (x) {
                    int y = x->field;
                    if (y) {
                        CIntangibleAction* z = (CIntangibleAction*)FUN_0008d690((int)sizeof(CIntangibleAction));
                        if (z)
                            return (hulk_intptr)(((CIntangibleAction_nv_5b4f0*)(((CIntangibleAction*)(z))))->Init_0001f560(y));
                    }
                }
            }
        }
    }
    return (int)(0);
}

