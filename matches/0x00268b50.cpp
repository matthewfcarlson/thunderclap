#include "gen/core.h"

void* core::ControllerXBox::vfunc_16(unsigned int index) {
    if (index < 2)
        return (void*)((char*)this + index * 16 + 0x428);
    return (void*)(0);
}
