// STATUS: equivalent (tools/equiv.py level 3: 20005 inputs, branch coverage 6/6)
// FUN_00212fb0 @ 0x00212fb0
// FUN_00212fb0 @ 0x00212fb0
#include "decls/data/engine/unknown.h"

int *__fastcall FUN_00212bb0(void *second, void *first);
int __cdecl FUN_00212fb0(void *first, void *second) {
    int *value = FUN_00212bb0(second, first);
    if (value == ((int*)&DAT_00426824)) return 0;
    return *value == 4 || *value == 3;
}
