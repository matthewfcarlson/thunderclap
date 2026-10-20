#include "compat/ptr.h"
extern "C" char hulk_at_004c83e8[];
unsigned int __stdcall SetX(unsigned int x) {
    *(unsigned int*)((hulk_intptr)hulk_at_004c83e8) = x;
    return x;
}