// lua_pushlightuserdata.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00213550(LuaVMState* L, void* p) {
    LuaVMTObject* o = L->top;
    o->value.p = p;
    o->tt = LUAVM_TLIGHTUSERDATA;
    L->top++;
}
