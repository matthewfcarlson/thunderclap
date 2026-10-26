#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void* memset(void*, int, unsigned int);

void pure3d::Image8::vfunc_16(hulk_intptr __p0, int __p1) { const unsigned int * src = (const unsigned int *)__p0; unsigned int n = (unsigned int)__p1;

    if (n != 256)
        memset((*(unsigned int (*)[256])&this->f_30), 0, sizeof (*(unsigned int (*)[256])&this->f_30));
    memcpy((*(unsigned int (*)[256])&this->f_30), src, n * 4);
}
