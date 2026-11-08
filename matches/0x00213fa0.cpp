// lua_gethookmask.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00213fa0(LuaVMState* L) {
    return L->hookmask;
}
