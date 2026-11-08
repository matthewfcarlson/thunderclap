// lua_settop: idx >= 0 sets the top to base + idx (new slots nil); idx < 0 drops -idx - 1 values.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx) {
    if (idx >= 0) {
        while (L->top < L->base + idx) {
            L->top->tt = LUAVM_TNIL;
            L->top++;
        }
        L->top = L->base + idx;
        return;
    }
    L->top += idx + 1;
}
