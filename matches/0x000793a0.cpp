#include "compat/ptr.h"
extern "C" char hulk_at_0049b8a0[];
extern "C" void __stdcall FUN_000793a0(float x) {
    float v = x * x;
    *(float*)((hulk_intptr)hulk_at_0049b8a0) = v;
}
