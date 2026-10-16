#include "gen/core.h"

void thunk(void*);

void core::MemoryAllocatorMalloc::vfunc_4(void* __p0) { void * p = (void *)__p0;

    thunk(p);
}
