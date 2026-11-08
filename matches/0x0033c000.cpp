// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 4/4)
// FUN_0033c000 @ 0x0033c000
// cl-flags: /GS
// string.rep
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* B);
extern "C" void __cdecl FUN_003394b0(LuaVMLBuffer* B, const char* s, unsigned int l);
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* B);

extern "C" int __cdecl FUN_0033c000(LuaVMState* L)
{
    unsigned int l;
    LuaVMLBuffer b;
    const char* s = FUN_00339df0(L, 1, &l);
    int n = FUN_00339f70(L, 2);
    FUN_00339630(L, &b);
    while (n > 0) {
        FUN_003394b0(&b, s, l);
        n--;
    }
    FUN_00339540(&b);
    return 1;
}
