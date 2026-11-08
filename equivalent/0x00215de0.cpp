// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 6/6)
// luaD_pcall: call func(L, u) protected with error function ef; on an error restore the stack (to the byte
// offset oldtop), the call depth, the CallInfo and the hooks, and set the error object.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_002152f0(LuaVMState* L, void(__cdecl* f)(LuaVMState* L, void* ud), void* ud);
extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMStkId level);
// equiv-conv: FUN_00215240 eax ecx edi
extern "C" void __cdecl FUN_00215240(int errcode, LuaVMTObject* oldtop, LuaVMState* L);
extern "C" void __cdecl FUN_00215410(LuaVMState* L, int newsize);

extern "C" int __cdecl FUN_00215de0(LuaVMState* L, void(__cdecl* func)(LuaVMState* L, void* ud), void* u, int oldtop,
                                    int ef) {
    unsigned short oldnCcalls = L->nCcalls;
    unsigned char old_allowhooks = L->allowhook;
    int old_ci = (int)((char*)L->ci - (char*)L->base_ci);
    int old_errfunc = L->errfunc;
    L->errfunc = ef;
    int status = FUN_002152f0(L, func, u);
    if (status) {
        LuaVMTObject* oldtopp = (LuaVMTObject*)((char*)L->stack + oldtop);
        FUN_00219660(L, oldtopp);
        FUN_00215240(status, oldtopp, L);
        bool large = L->size_ci > 0x1000;
        LuaVMCallInfo* base_ci = L->base_ci;
        LuaVMTObject* stack = L->stack;
        L->nCcalls = oldnCcalls;
        LuaVMCallInfo* ci = (LuaVMCallInfo*)((char*)base_ci + old_ci);
        L->ci = ci;
        L->base = ci->base;
        L->allowhook = old_allowhooks;
        L->stack_last = stack + L->stacksize - 1;
        if (large && (int)(ci - base_ci) + 1 < 0x1000)
            FUN_00215410(L, 0x1000);
    }
    L->errfunc = old_errfunc;
    return status;
}
