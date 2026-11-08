// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033db20 @ 0x0033db20
// luaB_setfenv
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
// equiv-conv: FUN_0033d9e0 esi
void __cdecl FUN_0033d9e0(LuaVMState* L);
extern "C" void __cdecl FUN_00213720(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx);
extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212e60(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213950(LuaVMState* L, int idx);

extern "C" int __cdecl FUN_0033db20(LuaVMState* L) {
    FUN_00339d70(L, 2, LUAVM_TTABLE);
    FUN_0033d9e0(L);
    FUN_00213720(L, -1);
    FUN_00213380(L, "__fenv", 6);
    FUN_00213600(L, -2);
    if (FUN_00212f00(L, -1))
        FUN_00338e20(L, "`setfenv' cannot change a protected environment");
    else
        FUN_00212d80(L, -3);
    FUN_00212ed0(L, 2);
    if (FUN_00212f70(L, 1)) {
        if (FUN_002130e0(L, 1) == 0.0f) {
            FUN_00212e60(L, -10001);
            return 0;
        }
    }
    if (!FUN_00213950(L, -2))
        FUN_00338e20(L, "`setfenv' cannot change environment of given function");
    return 0;
}
