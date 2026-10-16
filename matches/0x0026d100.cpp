#include "gen/core.h"

bool core::MemoryTwoWayAllocator::vfunc_9(void* __p0, void* __p1, void* __p2, void* __p3) { int * p = (int *)__p0; int * q = (int *)__p1; int * r = (int *)__p2; int * s = (int *)__p3;

    if (p)
        *p = this->f_1c - this->f_18;
    if (q)
        *q = this->f_1c - this->f_18;
    if (r)
        *r = this->f_24 + this->f_20;
    if (s)
        *s = ((this->f_18 - this->f_1c) - this->f_10) + this->f_14;
    return true;
}
