// luaB_type
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);

extern "C" int __cdecl FUN_0033dd60(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    FUN_002133d0(L, FUN_00212f20(L, FUN_00212f00(L, 1)));
    return 1;
}
