// luaB_setmetatable
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" int __cdecl FUN_00339010(LuaVMState* L, int obj, const char* event);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_002138e0(LuaVMState* L, int objindex);

extern "C" int __cdecl FUN_0033d960(LuaVMState* L) {
    int t = FUN_00212f00(L, 2);
    FUN_00339d70(L, 1, LUAVM_TTABLE);
    if (t != LUAVM_TNIL && t != LUAVM_TTABLE)
        FUN_00339c30(L, 2, "nil or table expected");
    if (FUN_00339010(L, 1, "__metatable"))
        FUN_00338e20(L, "cannot change a protected metatable");
    FUN_00212d80(L, 2);
    FUN_002138e0(L, 1);
    return 1;
}
