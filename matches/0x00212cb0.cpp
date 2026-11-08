// lua_xmove: move n values from the top of from's stack to to's.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00212cb0(LuaVMState* from, LuaVMState* to, int n) {
    if (from == to)
        return;
    from->top -= n;
    for (int i = 0; i < n; ++i) {
        LUAVM_SETOBJ(to->top, from->top + i);
        ++to->top;
    }
}
