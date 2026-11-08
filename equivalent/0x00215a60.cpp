// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 8/8)
// resume: the protected body of lua_resume: start the coroutine's function, or finish the yielding call, then
// run the Lua code. The suspended flag is the byte at 0x32 (LuaVMState.status in the records).
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00215790(LuaVMState* L, LuaVMTObject* func);
extern "C" void __cdecl FUN_00215970(LuaVMState* L, int wanted, LuaVMTObject* firstResult);
extern "C" LuaVMTObject* __cdecl FUN_00218350(LuaVMState* L, int nexeccalls);

extern "C" void __cdecl FUN_00215a60(LuaVMState* L, void* ud) {
    int nargs = *(int*)ud;
    if (!L->status) {
        FUN_00215790(L, L->top - (nargs + 1));
    } else if (((LuaVMClosure*)(L->ci->base - 1)->value.gc)->c.isC) {
        LuaVMInstruction inst = L->ci[-1].savedpc[-1];
        int nresults = (int)((inst >> 6) & 0x1ff) - 1;
        FUN_00215970(L, nresults, L->top - nargs);
        if (nresults >= 0)
            L->top = L->ci->top;
    }
    L->status = 0;
    LuaVMTObject* firstResult = FUN_00218350(L, (int)(L->ci - L->base_ci));
    if (firstResult)
        FUN_00215970(L, -1, firstResult);
}
