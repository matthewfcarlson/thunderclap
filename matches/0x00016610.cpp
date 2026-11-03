// Same code shape as 0x00016580 (propagated; names are from that function)
#include "gen/global.h"
#include "gen/owners.h"

struct ObjA_16610 {
};
struct ObjB_16610 {
    ObjB_16610* g();
};
struct ObjC_16610 {
    void h(int);
};

bool CIntangibleToActorsAction::vfunc_6(int ) {
    ObjA_16610* a = ((ObjA_16610 *)((owners::Object_592a0 *)((*(ObjA_16610 * *)&this->f_1c)))->FUN_000592a0());
    ObjB_16610* b = ((ObjB_16610*)a)->g();
    ((ObjC_16610*)b)->h(1);
    return true;
}
