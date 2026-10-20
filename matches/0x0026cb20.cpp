#include "compat/ptr.h"
#include "gen/core.h"

namespace core {

} // namespace core
bool core::MemoryDlAllocator::vfunc_5(void* __p0) { hulk_uintptr p = (hulk_uintptr)__p0;

    if (p >= (*(unsigned int *)&this->f_0c) && p < (*(unsigned int *)&this->f_10) || p == 0)
        return true;
    return false;
}
