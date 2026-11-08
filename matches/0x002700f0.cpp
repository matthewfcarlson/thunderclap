#include "compat/ptr.h"
#include "gen/core.h"

// core::MemoryPool::vfunc_5: does the address lie in this pool's block (or a child pool's)
bool core::MemoryPool::vfunc_5(void* __p0) {
    hulk_uintptr p = (hulk_uintptr)__p0;
    hulk_uintptr s = this->f_18;
    if (p >= s && p < this->f_20 * this->f_1c + s)
        return true;
    if (this->f_30)
        return ((core::MemoryPool*)this->f_30)->vfunc_5((void*)p);
    return false;
}
