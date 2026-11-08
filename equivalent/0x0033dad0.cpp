// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033dad0 @ 0x0033dad0
// luaB_getfenv
#include "decls/data/lua.h"

// equiv-conv: FUN_0033d9e0 esi
void __cdecl FUN_0033d9e0(LuaVMState* L);
extern "C" void __cdecl FUN_00213720(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);

extern "C" int __cdecl FUN_0033dad0(LuaVMState* L) {
    FUN_0033d9e0(L);
    FUN_00213720(L, -1);
    FUN_00213380(L, "__fenv", 6);
    FUN_00213600(L, -2);
    if (FUN_00212f00(L, -1) == LUAVM_TNIL)
        FUN_00212d80(L, -2);
    return 1;
}
