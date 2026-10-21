#include "compat/ptr.h"
extern "C" float g_limit_1e8780;
extern "C" float g_accum;
extern "C" const float g_bias = 4294967296.0f;

extern "C" bool __stdcall FUN_001e8780(int value) {
    hulk_freg next = (hulk_freg)value;
    if (value < 0)
        next += g_bias;
    next += g_accum;
    if (next < g_limit_1e8780) {
        g_accum = next;
        return true;
    }
    return false;
}