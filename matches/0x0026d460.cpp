// Same code shape as 0x0026d420 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/core.h"

void core::MemoryTwoWayAllocator::vfunc_7(void* __p0) { hulk_uintptr n = (hulk_uintptr)__p0;

    if (n) {
        if (n < (*(unsigned int *)&this->f_1c))
            --this->f_20;
        else
            --this->f_24;
    }
}
