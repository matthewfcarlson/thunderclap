#include "decls/data/game/global.h"

extern "C" int __cdecl FUN_000f7120(int param_1);

int __cdecl FUN_000f7120(int param_1) {
    int iVar1 = 0;
    do {
        if (((int*)&DAT_0040cc74)[iVar1 * 2] == param_1) {
            return ((int*)&DAT_0040cc78)[iVar1 * 2];
        }
        iVar1 = iVar1 + 1;
    } while (iVar1 < 6);
    return 0;
}