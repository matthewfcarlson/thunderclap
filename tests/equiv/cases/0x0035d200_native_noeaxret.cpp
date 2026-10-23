#include "compat/ptr.h"
extern "C" char hulk_at_004dd940[];
extern "C" double __cdecl cos(double);
extern "C" void __cdecl FUN_0035d200() {
    hulk_freg r = cos(0.017453293005625408);
    *(volatile float*)((hulk_intptr)hulk_at_004dd940) = 1.0f - r;
}
