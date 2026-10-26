#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" void* memcpy(void*, const void*, unsigned);

int fight::BufferDataReader::vfunc_4(hulk_intptr __p0, int __p1) { void * dst = (void *)__p0; unsigned int n = (unsigned int)__p1;

    unsigned available = this->f_10 - this->f_14;
    if (available < n)
        n = available;
    memcpy(dst, (*(char * *)&this->f_08) + this->f_14, n);
    this->f_14 += n;
    return (int)(n);
}
