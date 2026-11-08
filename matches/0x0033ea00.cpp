// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033ea00 @ 0x0033ea00
// cl-flags: /GS
// Lua coroutine.status
#include "decls/data/lua.h"

extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" int __cdecl FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);

extern "C" int __cdecl FUN_0033ea00(LuaVMState* L) {
    LuaVMDebug ar;
    LuaVMState* co = FUN_00213290(L, 1);
    if (co == 0)
        FUN_00339c30(L, 1, "coroutine expected");
    if (L == co) {
        FUN_00213380(L, "running", 7);
    } else if (FUN_00213fc0(co, 0, &ar) == 0 && FUN_00212d70(co) == 0) {
        FUN_00213380(L, "dead", 4);
    } else {
        FUN_00213380(L, "suspended", 9);
    }
    return 1;
}
