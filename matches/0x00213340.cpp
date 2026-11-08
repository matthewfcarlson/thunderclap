// lua_pushnumber.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n) {
    LuaVMTObject* o = L->top;
    o->value.n = n;
    o->tt = LUAVM_TNUMBER;
    L->top++;
}
