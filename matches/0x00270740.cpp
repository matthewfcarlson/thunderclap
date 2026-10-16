#include "gen/core.h"

extern "C" void* memcpy(void*, const void*, unsigned int);

unsigned int core::ControllerBuffer::vfunc_5(void* __p0) { const void * src = (const void *)__p0;

    memcpy((void*)(*(unsigned int * *)&this->f_24)[this->f_20], src, this->f_18);
    unsigned int n = (this->f_20 + 1) % this->f_14;
    unsigned int r = this->f_1c;
    this->f_20 = n;
    if (n == r) {
        r = r + 1;
        this->f_1c = r % this->f_14;
        return r / this->f_14;
    }
    return r;
}
