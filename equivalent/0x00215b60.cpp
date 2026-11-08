// STATUS: equivalent (tools/equiv.py level 3: 2976 inputs, branch coverage 10/10)
// lua_yield: from a C function, keep only its nresults results; mark the thread suspended (the byte at 0x32,
// LuaVMState.status in the records).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);

extern "C" int __cdecl FUN_00215b60(LuaVMState* L, int nresults) {
    LuaVMCallInfo* ci = L->ci;
    if (L->nCcalls > 0)
        FUN_00214a90(L, "attempt to yield across metamethod/C-call boundary");
    if (((LuaVMClosure*)(ci->base - 1)->value.gc)->c.isC) {
        if (L->top - nresults > L->base) {
            for (int i = 0; i < nresults; i++)
                LUAVM_SETOBJ(L->base + i, L->top + (i - nresults));
            L->top = L->base + nresults;
        }
    }
    L->status = 1;
    return -1;
}
