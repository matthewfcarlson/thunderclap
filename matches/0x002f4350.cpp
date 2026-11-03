#include "compat/ptr.h"
typedef unsigned short u16_2f4350;
void FUN_002f40f0(u16_2f4350*, hulk_intptr, hulk_intptr, u16_2f4350);
void FUN_002f4350(u16_2f4350* first, u16_2f4350* last) {
    hulk_intptr count = ((char*)last - (char*)first) >> 1;
    hulk_intptr i = count / 2;
    while (i > 0) {
        --i;
        u16_2f4350 v = first[i];
        FUN_002f40f0(first, i, count, v);
    }
}