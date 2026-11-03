#include "decls/data/game/global.h"
// data: Zero_a0010 = DAT_003f32e0

#include "compat/ptr.h"
extern "C" int __cdecl FUN_0009fa70(int*, int*, int*);
int __cdecl FUN_000a0010(float length, float spacing, int maxCount, float* out) {
    if (length < DAT_003f32e0 || maxCount <= 0 || spacing <= DAT_003f32e0)
        return -1;
    int count;
    hulk_freg step;
    if (length == DAT_003f32e0 || maxCount == 1) {
        count = 1;
        step = DAT_003f32e0;
    } else {
        int local4 = (int)(length / spacing) + 1;
        int local8 = 2;
        count = FUN_0009fa70(&local4, &local8, &maxCount);
        step = length / (float)(count - 1);
    }
    for (int i = 0; i < count; ++i)
        out[i] = (float)i * step;
    return count;
}
