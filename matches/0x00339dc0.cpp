// luaL_checkany
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int index) {
    if (FUN_00212f00(L, index) == -1)
        FUN_00339c30(L, index, "value expected");
}
