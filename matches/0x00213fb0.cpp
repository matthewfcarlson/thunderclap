// lua_gethookcount.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00213fb0(LuaVMState* L) {
    return L->basehookcount;
}
