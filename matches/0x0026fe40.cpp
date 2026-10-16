#include "gen/core.h"

void core::MemoryPool::vfunc_14(void* __p0, void* __p1, void* __p2) { int * p = (int *)__p0; int * q = (int *)__p1; int * r = (int *)__p2;

    if (p)
        *p = 0;
    if (q)
        *q = 0;
    if (r)
        *r = 0;
    if ((*(core::MemoryPool * *)&this->f_30))
        (*(core::MemoryPool * *)&this->f_30)->vfunc_14(p, q, r);
    if (p)
        *p += this->f_1c;
    if (q)
        *q += this->f_20 - this->f_28;
    if (r)
        *r += this->f_28;
}
