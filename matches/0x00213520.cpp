// lua_pushboolean.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00213520(LuaVMState* L, int b) {
    LuaVMTObject* o = L->top;
    o->tt = LUAVM_TBOOLEAN;
    o->value.b = (b != 0);
    L->top++;
}
