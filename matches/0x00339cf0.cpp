// luaL_typerror
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"
// data: fmt = DAT_004346e4

extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" int __cdecl FUN_00339cf0(LuaVMState* x, int y, const char* z) {
    return FUN_00339c30(x, y, FUN_00213470(x, DAT_004346e4, z, FUN_00212f20(x, FUN_00212f00(x, y))));
}
