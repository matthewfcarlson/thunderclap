#include "compat/ptr.h"
#include "gen/core.h"

namespace core {

} // namespace core
bool core::MemoryDlAllocator::vfunc_8(void* __p0) { void * p = (void *)__p0;

    hulk_uintptr x = (hulk_uintptr)p;
    if (x < (*(unsigned int *)&this->f_0c) || x >= (*(unsigned int *)&this->f_10)) {
        if (x == 0)
            goto yes;
        return false;
    }
yes:
    return true;
}
