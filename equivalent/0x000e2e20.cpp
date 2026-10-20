// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// HSlider::vfunc_6 @ 0x000e2e20
#include "gen/global.h"

struct Other { void FUN_000f9530(int, int, void *); };

void HSlider::vfunc_6(int __p0) { Other * other = (Other *)__p0;

    if (this->f_90 || this->f_94) {
        other->FUN_000f9530(this->f_90, this->f_94, (*(void * *)&this->f_150));
    }
}
