#include "compat/ptr.h"
typedef unsigned short u16_2f4350;
void FUN_002f40f0(u16_2f4350*, hulk_intptr, hulk_intptr, u16_2f4350);
void FUN_002f4350(u16_2f4350* param_1, u16_2f4350* param_2) {
    hulk_intptr count = ((char*)param_2 - (char*)param_1) >> 1;
    hulk_intptr i = count / 2;
    while (i > 0) {
        --i;
        u16_2f4350 v = param_1[i];
        FUN_002f40f0(param_1, i, count, v);
    }
}