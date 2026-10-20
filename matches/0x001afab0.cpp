#include "compat/ptr.h"
extern "C" char hulk_at_004c3710[];
extern "C" char hulk_at_004c3714[];
extern "C" void __cdecl FUN_001afab0(int b, int a) {
    *(__int32*)((hulk_intptr)hulk_at_004c3714) = a;
    *(__int32*)((hulk_intptr)hulk_at_004c3710) = b;
}
