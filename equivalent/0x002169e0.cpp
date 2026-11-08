// STATUS: equivalent (tools/equiv.py level 3: 145 inputs, branch coverage 30/30)
// traversestack: mark a thread's globals and live stack, clear the slots above, and shrink the CallInfo array and
// the stack when little is used.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);
extern "C" void __cdecl FUN_00215410(LuaVMState* L, int newsize);
extern "C" void __cdecl FUN_002153d0(LuaVMState* L, int newsize);

// equiv-conv: FUN_002169e0 edi stack
extern "C" void __cdecl FUN_002169e0(LuaVMState* L, LuaVMGlobal* g) {
    if (L->_gt.tt >= LUAVM_TSTRING && (L->_gt.value.gc->marked & 3))
        FUN_002164b0(g, L->_gt.value.gc);
    LuaVMTObject* top = L->top;
    LuaVMTObject* lim = top;
    for (LuaVMCallInfo* ci = L->base_ci; ci <= L->ci; ++ci)
        if (lim < ci->top)
            lim = ci->top;
    LuaVMTObject* o = L->stack;
    if (o < top) {
        do {
            if (o->tt >= LUAVM_TSTRING && (o->value.gc->marked & 3))
                FUN_002164b0(g, o->value.gc);
            ++o;
        } while (o < L->top);
    }
    for (; o <= lim; ++o)
        o->tt = LUAVM_TNIL;
    int ci_used = (int)(L->ci - L->base_ci) * 4;
    unsigned int size_ci = L->size_ci;
    if (ci_used < (int)size_ci && size_ci > 16)
        FUN_00215410(L, (int)(size_ci >> 1));
    int s_used = (int)(lim - L->stack) * 4;
    if (s_used < L->stacksize && L->stacksize > 90)
        FUN_002153d0(L, L->stacksize / 2);
}
