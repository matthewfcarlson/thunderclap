#include "gen/owners.h"
typedef unsigned int u32_1d19d0;
extern void __cdecl Callee(u32_1d19d0, u32_1d19d0);
unsigned char owners::Obj_1d19d0::FUN_001d19d0(u32_1d19d0 arg) {
    Callee(value, 0xffffffffu - arg);
    return 1;
}