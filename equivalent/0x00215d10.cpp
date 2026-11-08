// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 12/12)
// lua_resume: resume a suspended coroutine (or start it); on an error the thread is reset to its base.
// The suspended flag is the byte at 0x32 (LuaVMState.status in the records).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00215a60(LuaVMState* L, void* ud);
// equiv-conv: FUN_00215b00 esi edx
extern "C" int __cdecl FUN_00215b00(LuaVMState* L, const char* msg);
extern "C" int __cdecl FUN_002152f0(LuaVMState* L, void(__cdecl* f)(LuaVMState* L, void* ud), void* ud);
extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMStkId level);
// equiv-conv: FUN_00215240 eax ecx edi
extern "C" void __cdecl FUN_00215240(int errcode, LuaVMTObject* oldtop, LuaVMState* L);
extern "C" void __cdecl FUN_00215410(LuaVMState* L, int newsize);

extern "C" int __cdecl FUN_00215d10(LuaVMState* L, int nargs) {
    if (!L->status) {
        if (L->ci != L->base_ci)
            return FUN_00215b00(L, "cannot resume non-suspended coroutine");
        if (nargs >= L->top - L->base)
            return FUN_00215b00(L, "cannot resume dead coroutine");
    }
    unsigned char old_allowhooks = L->allowhook;
    int status = FUN_002152f0(L, FUN_00215a60, &nargs);
    if (status) {
        L->ci = L->base_ci;
        LuaVMStkId base = L->ci->base;
        L->base = base;
        L->nCcalls = 0;
        FUN_00219660(L, base);
        FUN_00215240(status, L->base, L);
        bool grow = L->size_ci > 0x1000;
        L->allowhook = old_allowhooks;
        L->stack_last = L->stack + L->stacksize - 1;
        if (grow && (L->ci - L->base_ci) + 1 < 0x1000)
            FUN_00215410(L, 0x1000);
    }
    return status;
}
