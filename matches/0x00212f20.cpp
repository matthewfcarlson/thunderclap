// lua_typename: the name of type tag t ("no value" for LUA_TNONE).
#include "decls/data/lua.h"
#include "decls/data/engine/unknown.h"

extern "C" const char* __cdecl FUN_00212f20(LuaVMState* L, int t) {
    if (t == -1)
        return DAT_004265fc;
    return DAT_00426948[t];
}
