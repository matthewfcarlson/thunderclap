// lua_gethook.
#include "decls/data/lua.h"

extern "C" LuaVMHook __cdecl FUN_00213f90(LuaVMState* L) {
    return L->hook;
}
