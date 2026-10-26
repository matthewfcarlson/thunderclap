#include "compat/ptr.h"
#include "gen/core.h"

typedef unsigned int uint_270790;
extern "C" void* memcpy(void*, const void*, uint_270790);

bool core::ControllerBuffer::vfunc_6(hulk_intptr __p0, int __p1) { void * dst = (void *)__p0; uint_270790 size = (uint_270790)__p1;

    if ((*(int *)&this->f_1c) == (*(int *)&this->f_20))
        return false;
    memcpy(dst, (*(char ** *)&this->f_24)[(*(int *)&this->f_1c)], size);
    return true;
}
