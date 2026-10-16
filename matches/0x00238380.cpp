#include "gen/fight.h"

bool fight::RandomCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { int a = (int)__p0; int b = (int)__p1; float * out = (float *)__p2;

    if (out)
        *out += this->f_0c;
    return true;
}
