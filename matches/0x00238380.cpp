#include "compat/ptr.h"
#include "gen/fight.h"

bool fight::RandomCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; float * out = (float *)__p2;

    if (out)
        *out += this->f_0c;
    return true;
}
