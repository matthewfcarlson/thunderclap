// luaL_checktype
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" void __cdecl FUN_00339d70(LuaVMState* a, int b, int c) {
    int x = FUN_00212f00(a, b);
    if (x != c) {
        const char* y = FUN_00212f20(a, c);
        int t = FUN_00212f00(a, b);
        const char* z = FUN_00212f20(a, t);
        z = FUN_00213470(a, "%s expected, got %s", y, z);
        FUN_00339c30(a, b, z);
    }
}
