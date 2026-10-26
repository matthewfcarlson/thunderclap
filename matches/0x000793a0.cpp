#include "decls/data/game/global.h"
// data: hulk_at_0049b8a0 = DAT_0049b8a0

#include "compat/ptr.h"
extern "C" void __stdcall FUN_000793a0(float x) {
    float v = x * x;
    *(float*)((hulk_intptr)((char*)&DAT_0049b8a0)) = v;
}
