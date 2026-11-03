#include "gen/global.h"
#include "gen/owners.h"

struct Obj2_16440;
struct Obj1_16440 {
};
struct Obj2_16440 {
    Obj2_16440* second();
};

bool CSmartPropThrowingAction::vfunc_6(int x) {
    Obj2_16440* p = ((Obj2_16440 *)((owners::Object_592a0 *)((*(Obj1_16440 * *)&this->f_1c)))->FUN_000592a0());
    Obj2_16440* q = p->second();
    *((char*)q + 0x1f51) = 1;
    return true;
}
