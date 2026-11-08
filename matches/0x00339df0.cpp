// luaL_checklstring
#include "decls/data/lua.h"
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00339df0(LuaVMState* a, int b, unsigned int* out) {
    const char* r = FUN_00213190(a, b);
    if (!r) {
        const char* x = FUN_00212f20(a, 4);
        const char* y = FUN_00212f20(a, FUN_00212f00(a, b));
        FUN_00339c30(a, b, FUN_00213470(a, "%s expected, got %s", x, y));
    }
    if (out)
        *out = FUN_002131f0(a, b);
    return r;
}
