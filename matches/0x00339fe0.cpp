// luaL_optint
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* a, int b, int c) {
    int r = FUN_00212f00(a, b);
    if (r <= 0)
        return c;
    return FUN_00339f70(a, b);
}
