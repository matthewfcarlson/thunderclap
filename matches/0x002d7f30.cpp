#include "compat/ptr.h"
typedef unsigned char u8_2d7f30;
typedef int i32_2d7f30;
u8_2d7f30 __cdecl target(i32_2d7f30 a, hulk_intptr b) {
    if (a && b)
        return *(u8_2d7f30*)(b + 0x19);
    return 0;
}