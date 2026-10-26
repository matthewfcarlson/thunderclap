#include "decls/data/game/global.h"
// data: Zero_a0010 = DAT_003f32e0

#include "compat/ptr.h"
extern int __cdecl Build(int*, int*, int*);
int __cdecl FUN_000a0010(float param_1, float param_2, int param_3, float* param_4) {
    if (param_1 < DAT_003f32e0 || param_3 <= 0 || param_2 <= DAT_003f32e0)
        return -1;
    int count;
    hulk_freg step;
    if (param_1 == DAT_003f32e0 || param_3 == 1) {
        count = 1;
        step = DAT_003f32e0;
    } else {
        int local4 = (int)(param_1 / param_2) + 1;
        int local8 = 2;
        count = Build(&local4, &local8, &param_3);
        step = param_1 / (float)(count - 1);
    }
    for (int i = 0; i < count; ++i)
        param_4[i] = (float)i * step;
    return count;
}
