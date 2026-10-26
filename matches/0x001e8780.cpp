#include "decls/data/game/unknown.h"
// data: g_accum = DAT_004e36a8, g_limit_1e8780 = DAT_004e36a4

#include "compat/ptr.h"
extern "C" const float g_bias = 4294967296.0f;

extern "C" bool __stdcall FUN_001e8780(int value) {
    hulk_freg next = (hulk_freg)value;
    if (value < 0)
        next += g_bias;
    next += (*(float*)&DAT_004e36a8);
    if (next < DAT_004e36a4) {
        (*(float*)&DAT_004e36a8) = next;
        return true;
    }
    return false;
}