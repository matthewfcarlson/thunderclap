// Same code shape as 0x00267220 (propagated; names are from that function)
#include "gen/core.h"

void thunk(void*);

void core::MemoryAllocatorMalloc::vfunc_7(void* __p0) { void * p = (void *)__p0;

    thunk(p);
}
