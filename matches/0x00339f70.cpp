// luaL_checkint
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00213120(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int o) {
    int r = FUN_00213120(L, o);
    if (r == 0) {
        if (FUN_00212f70(L, o) == 0) {
            const char* a = FUN_00212f20(L, 3);
            const char* b = FUN_00212f20(L, FUN_00212f00(L, o));
            FUN_00339c30(L, o, FUN_00213470(L, "%s expected, got %s", a, b));
        }
    }
    return r;
}
