// luaL_getmetafield: pushes the metatable's field event of obj; 0 (nothing pushed) when absent.
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_002136d0(LuaVMState* L, int objindex);
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212de0(LuaVMState* L, int idx);

extern "C" int __cdecl FUN_00339010(LuaVMState* L, int obj, const char* event) {
    if (!FUN_002136d0(L, obj))
        return 0;
    FUN_002135a0(L, -1, event);
    if (!FUN_00212f00(L, -1)) {
        FUN_00212d80(L, -3);
        return 0;
    }
    FUN_00212de0(L, -2);
    return 1;
}
