#include "gen/core.h"

typedef unsigned int u32_2706a0;
extern void Free(void*, void*);
extern void* Alloc(void*, u32_2706a0);

void core::ControllerBuffer::vfunc_4(int __p0) { u32_2706a0 n = (u32_2706a0)__p0;

    if ((*(u32_2706a0 *)&this->f_14) == n)
        return;
    if ((*(void * *)&this->f_10) && (*(void * *)&this->f_24)) {
        Free((*(void * *)&this->f_28), (*(void * *)&this->f_10));
        Free((*(void * *)&this->f_28), (*(void * *)&this->f_24));
    }
    (*(u32_2706a0 *)&this->f_14) = n;
    (*(void * *)&this->f_10) = Alloc((*(void * *)&this->f_28), (*(u32_2706a0 *)&this->f_18) * n);
    (*(void * *)&this->f_24) = Alloc((*(void * *)&this->f_28), (*(u32_2706a0 *)&this->f_14) * 4);
    for (u32_2706a0 i = 0; i < (*(u32_2706a0 *)&this->f_14); ++i)
        ((void**)(*(void * *)&this->f_24))[i] = (char*)(*(void * *)&this->f_10) + (*(u32_2706a0 *)&this->f_18) * i;
    (*(u32_2706a0 *)&this->f_1c) = 0;
    (*(u32_2706a0 *)&this->f_20) = 0;
}
