#include "gen/global.h"

struct A_17540 {
    A_17540* get();
    A_17540* valid();
    void apply(void*, int);
};

void COrientTargetAction::vfunc_4() {
    A_17540* a = (*(A_17540 * *)&this->f_1c)->get();
    a = a->valid();
    if (a)
        a->apply((*(void * *)&this->f_28), 0);
}
