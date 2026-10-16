#include "gen/core.h"

bool core::MemoryDlAllocator::vfunc_9(void* __p0, void* __p1, void* __p2, void* __p3) { int * p1 = (int *)__p0; int * p2 = (int *)__p1; int * p3 = (int *)__p2; int * p4 = (int *)__p3;

    if (p1)
        *p1 = this->f_14 - this->f_494;
    if (p2)
        *p2 = 0;
    if (p3)
        *p3 = this->f_490;
    if (p4)
        *p4 = this->f_498;
    return true;
}
