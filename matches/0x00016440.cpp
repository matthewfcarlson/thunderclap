#include "gen/global.h"

struct Obj2_16440;
struct Obj1_16440 {
    Obj2_16440* first();
};
struct Obj2_16440 {
    Obj2_16440* second();
};

bool CSmartPropThrowingAction::vfunc_6(int x) {
    Obj2_16440* p = (*(Obj1_16440 * *)&this->f_1c)->first();
    Obj2_16440* q = p->second();
    *((char*)q + 0x1f51) = 1;
    return true;
}
