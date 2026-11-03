#include "gen/global.h"
#include "gen/owners.h"

struct A_17540 {
    A_17540* valid();
    void apply(void*, int);
};

void COrientTargetAction::vfunc_4() {
    A_17540* a = ((A_17540 *)((owners::Object_592a0 *)((*(A_17540 * *)&this->f_1c)))->FUN_000592a0());
    a = a->valid();
    if (a)
        a->apply((*(void * *)&this->f_28), 0);
}
