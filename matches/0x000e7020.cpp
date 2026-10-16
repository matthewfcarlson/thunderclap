#include "gen/global.h"

extern "C" void* memset(void*, int, unsigned int);

void FEThingsBase::vfunc_24() {
    memset((char*)this + 0x1770, 0, 0x40);
    *(unsigned int*)((char*)this + 0x17b0) = 0xffffffff;
}
