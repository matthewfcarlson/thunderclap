#include "gen/core.h"

extern void __stdcall FUN_0020bbc2(void*);

int core::XboxDrive::vfunc_10(void* __p0, int q) { void * p = (void *)__p0;

    FUN_0020bbc2(p);
    --(*(int*)((char*)this + 0xc0));
    return 1;
}
