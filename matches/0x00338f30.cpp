// luaL_getmetatable: registry[tname].
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_00338f30(LuaVMState* L, const char* tname) {
    FUN_002135a0(L, -10000, tname);
}
