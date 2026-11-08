// lua_pushnil.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00213320(LuaVMState* L) {
    L->top->tt = LUAVM_TNIL;
    L->top++;
}
