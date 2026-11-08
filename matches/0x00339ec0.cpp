// luaL_checknumber
#include "decls/data/lua.h"
#include "decls/data/game/global.h"
// data: Zero_339ec0 = DAT_003f32e0

extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" float __cdecl FUN_00339ec0(LuaVMState* a, int b) {
    float f = FUN_002130e0(a, b);
    if (f == DAT_003f32e0) {
        if (FUN_00212f70(a, b) == 0) {
            const char* x = FUN_00212f20(a, 3);
            const char* y = FUN_00212f20(a, FUN_00212f00(a, b));
            FUN_00339c30(a, b, FUN_00213470(a, "%s expected, got %s", x, y));
        }
    }
    return f;
}
