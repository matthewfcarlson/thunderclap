// luaL_optnumber
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" float __cdecl FUN_00339ec0(LuaVMState* L, int narg);
extern "C" float __cdecl FUN_00339f40(LuaVMState* L, int index, float fallback) {
    int value = FUN_00212f00(L, index);
    if (value <= 0)
        return fallback;
    return FUN_00339ec0(L, index);
}
