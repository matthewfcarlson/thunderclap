// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033d9e0 @ 0x0033d9e0
// cl-flags: /GS
// lbaselib getfunc: push the function of argument 1 (a function or a stack level)
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" int __cdecl FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);

// equiv-conv: FUN_0033d9e0 esi
void __cdecl FUN_0033d9e0(LuaVMState* L) {
    LuaVMDebug ar;
    if (FUN_00212f00(L, 1) == LUAVM_TFUNCTION) {
        FUN_00212ed0(L, 1);
    } else {
        int level = FUN_00339fe0(L, 1, 1);
        if (level < 0)
            FUN_00339c30(L, 1, "level must be non-negative");
        if (!FUN_00213fc0(L, level, &ar))
            FUN_00339c30(L, 1, "invalid level");
        FUN_00214bd0(L, "f", &ar);
        if (!FUN_00212f00(L, -1))
            FUN_00338e20(L, "no function environment for tail call at level %d", level);
    }
}
