// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_00212fb0 @ 0x00212fb0
// equiv-conv: FUN_00212bb0 edx ecx
#include "decls/data/engine/unknown.h"

int *FUN_00212bb0(void *first, void *second);
int __cdecl FUN_00212fb0(void *first, void *second) {
    int *value = FUN_00212bb0(first, second);
    if (value == ((int*)&DAT_00426824)) return 0;
    return *value == 4 || *value == 3;
}