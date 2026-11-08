// lua_error: raise the error on top of the stack (luaG_errormsg does not return).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002149b0(LuaVMState* L);

extern "C" int __cdecl FUN_00213c40(LuaVMState* L) {
    FUN_002149b0(L);
    return 0;
}
