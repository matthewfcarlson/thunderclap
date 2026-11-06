#include "gen/core.h"

extern "C" void thunk_FUN_003479bc(void*);

void core::MemoryAllocatorMalloc::vfunc_4(void* __p0) { void * p = (void *)__p0;

    thunk_FUN_003479bc(p);
}
