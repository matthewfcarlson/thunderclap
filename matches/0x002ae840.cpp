#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" void* memcpy(void* dst, const void* src, unsigned int n);

namespace pure3d {
} // namespace pure3d
void pure3d::TextureBuilder::vfunc_3(hulk_intptr __p0, int __p1) { const void * src = (const void *)__p0; unsigned int n = (unsigned int)__p1;

    if ((*(int *)&this->f_04)) {
        memcpy((*(void * *)&this->f_14), src, n);
    }
}
