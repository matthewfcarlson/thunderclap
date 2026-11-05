// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 2/2)
// FUN_00212f00 @ 0x00212f00
// FUN_00212f00 @ 0x00212f00
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"

int* __fastcall FUN_00212bb0(int second, int first);

extern "C" int __cdecl FUN_00212f00(hulk_intptr first, int second)
{
    int* result = FUN_00212bb0(second, first);
    if (result == ((int*)&DAT_00426824))
        return -1;
    return *result;
}
