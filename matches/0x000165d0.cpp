// Same code shape as 0x00016580 (propagated; names are from that function)
#include "gen/global.h"

struct ObjA_165d0 {
    ObjA_165d0* f();
};
struct ObjB_165d0 {
    ObjB_165d0* g();
};
struct ObjC_165d0 {
    void h(int);
};

bool CIntangibleAction::vfunc_6(int ) {
    ObjA_165d0* a = (*(ObjA_165d0 * *)&this->f_1c)->f();
    ObjB_165d0* b = ((ObjB_165d0*)a)->g();
    ((ObjC_165d0*)b)->h(1);
    return true;
}
