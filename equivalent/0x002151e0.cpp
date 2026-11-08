// STATUS: equivalent (tools/equiv.py level 3: 2548 inputs, branch coverage 2/2)
// lua_close: on the main thread: close the upvalues, separate the udata, run the finalizers (until none errs),
// then close_state.
#include "decls/data/lua.h"

extern "C" void _ReadWriteBarrier();
extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMStkId level);
extern "C" unsigned int __cdecl FUN_002165c0(LuaVMState* L, int all);
extern "C" int __cdecl FUN_002152f0(LuaVMState* L, void(__cdecl* f)(LuaVMState* L, void* ud), void* ud);
// equiv-conv: FUN_00214f90 esi
extern "C" void __cdecl FUN_00214f90(LuaVMState* L);
extern "C" void __cdecl FUN_002151d0(LuaVMState* L, void* ud);

extern "C" void __cdecl FUN_002151e0(LuaVMState* L) {
    L = L->l_G->mainthread;
    FUN_00219660(L, L->stack);
    FUN_002165c0(L, 1);
    L->errfunc = 0;
    int r;
    do {
        LuaVMCallInfo* ci = L->base_ci;
        L->ci = ci;
        LuaVMStkId base = ci->base;
        L->top = base;
        L->base = base;
        L->nCcalls = 0;
        r = FUN_002152f0(L, FUN_002151d0, 0);
    } while (r != 0);
    FUN_00214f90(L);
    _ReadWriteBarrier();
}
