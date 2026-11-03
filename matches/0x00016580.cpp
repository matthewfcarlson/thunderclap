#include "gen/global.h"
#include "gen/owners.h"

struct ObjA_16580 {
};
struct ObjB_16580 {
    ObjB_16580* g();
};
struct ObjC_16580 {
    void h(int);
};

bool CInvincibleAction::vfunc_6(int ) {
    ObjA_16580* a = ((ObjA_16580 *)((owners::Object_592a0 *)((*(ObjA_16580 * *)&this->f_1c)))->FUN_000592a0());
    ObjB_16580* b = ((ObjB_16580*)a)->g();
    ((ObjC_16580*)b)->h(1);
    return true;
}
