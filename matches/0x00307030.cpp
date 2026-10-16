#include "decls/data/engine/physics.h"

typedef unsigned short u16_307030;
void __cdecl FUN_00307030(u16_307030 param_1) {
    if (*(*(u16_307030**)&DAT_0055543c) < 0x400) {
        (*(u16_307030**)&DAT_00555440)[*(*(u16_307030**)&DAT_0055543c)] = param_1;
        ++*(*(u16_307030**)&DAT_0055543c);
    }
}