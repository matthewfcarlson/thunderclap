#include "gen/core.h"

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

bool core::ControllerBuffer::vfunc_7(void* __p0) { void * output = (void *)__p0;

    if (this->f_1c == this->f_20)
        return false;
    memcpy(output, (void*)(*(unsigned int * *)&this->f_24)[this->f_1c], this->f_18);
    this->f_1c = (this->f_1c + 1) % this->f_14;
    return true;
}
