// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_003391f0 @ 0x003391f0
// getsizes: pushes registry[2], the weak-keyed table of explicit table sizes (created on first use).
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00213640(LuaVMState *L, int index, int n);
extern "C" int __cdecl FUN_00212f00(LuaVMState *L, int index);
extern "C" void __cdecl FUN_00212d80(LuaVMState *L, int index);
extern "C" void __cdecl FUN_00213680(LuaVMState *L, int narr, int nrec);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *L, int index);
extern "C" int __cdecl FUN_002138e0(LuaVMState *L, int index);
extern "C" void __cdecl FUN_00213380(LuaVMState *L, const char *s, unsigned int len);
extern "C" void __cdecl FUN_00213790(LuaVMState *L, int index, const char *key);
extern "C" void __cdecl FUN_00213870(LuaVMState *L, int index, int n);

// equiv-conv: FUN_003391f0 esi
extern "C" void __cdecl FUN_003391f0(LuaVMState *L)
{
    FUN_00213640(L, -10000, 2);
    if (FUN_00212f00(L, -1) == 0) {
        FUN_00212d80(L, -2);
        FUN_00213680(L, 0, 0);
        FUN_00212ed0(L, -1);
        FUN_002138e0(L, -2);
        FUN_00213380(L, "kv", 2);
        FUN_00213790(L, -2, "__mode");
        FUN_00212ed0(L, -1);
        FUN_00213870(L, -10000, 2);
    }
}
