#include "compat/ptr.h"
#include "decls/data/game/global.h"

extern "C" hulk_intptr __cdecl FUN_000f7120(int key);

hulk_intptr __cdecl FUN_000f7120(int key) {
    int i = 0;
    do {
        if (((int*)&DAT_0040cc74)[i * 2] == key) {
            return ((int*)&DAT_0040cc78)[i * 2];
        }
        i = i + 1;
    } while (i < 6);
    return 0;
}