// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_00212f00 @ 0x00212f00
// equiv-conv: FUN_00212bb0 ecx edx
#include "decls/data/engine/unknown.h"

int* FUN_00212bb0(int second, int first);

int __cdecl FUN_00212f00(int first, int second)
{
    int* result = FUN_00212bb0(second, first);
    if (result == ((int*)&DAT_00426824))
        return -1;
    return *result;
}
