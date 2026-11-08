// luaB_getmetatable
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_002136d0(LuaVMState* L, int objindex);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);
extern "C" int __cdecl FUN_00339010(LuaVMState* L, int obj, const char* event);

extern "C" int __cdecl FUN_0033d910(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    if (FUN_002136d0(L, 1) == 0) {
        FUN_00213320(L);
        return 1;
    }
    FUN_00339010(L, 1, "__metatable");
    return 1;
}
