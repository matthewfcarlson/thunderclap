// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 12/12)
// FUN_0015d4f0 @ 0x0015d4f0
#include "decls/data/game/hulkfight/motion.h"
#include "compat/ptr.h"

float __cdecl FUN_00224fc0(float a, float b);
float __cdecl FUN_0004af40(float lo, float hi, float v);

class Table_15d4f0 {
public:
    char pad0[0x24];
    float lo[4];
    float hi[4];
    hulk_freg FUN_0015d4f0(float t, float a, float b);
};

hulk_freg Table_15d4f0::FUN_0015d4f0(float t, float a, float b)
{
    if (!(t > 0.0f))
        return 0.0f;
    hulk_freg r1 = FUN_00224fc0(a, b);
    hulk_freg r2 = FUN_0004af40(0.0f, 6.2831855f, r1);
    if (!(DAT_004e11b8 & 1)) {
        DAT_004e11b8 |= 1;
        DAT_004e11b4 = 1.5707964f;
    }
    hulk_freg inv = 1.0f / DAT_004e11b4;
    int quad = (int)(inv * r2);
    int i0 = quad % 4;
    int i1 = (i0 + 1) % 4;
    hulk_freg f = (r2 - (float)i0 * DAT_004e11b4) * inv;
    if (!(t > 0.5f)) {
        return ((1.0f - f) * lo[i0] + f * lo[i1]) * (t + t);
    }
    if (t < 1.0f) {
        hulk_freg h = (t - 0.5f) + (t - 0.5f);
        hulk_freg a1 = (1.0f - f) * lo[i0] + f * lo[i1];
        hulk_freg b1 = (1.0f - f) * hi[i0] + f * hi[i1];
        return (1.0f - h) * a1 + b1 * h;
    }
    return ((1.0f - f) * hi[i0] + f * hi[i1]) * t;
}
