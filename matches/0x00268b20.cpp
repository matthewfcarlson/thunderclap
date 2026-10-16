#include "gen/core.h"

void* core::ControllerXBox::vfunc_11(unsigned int index) {
    if (index < this->f_14)
        return (void*)((core::ControllerXBox*)((char*)this + index * 0x34 + 0x18));
    return (void*)(0);
}
