// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 22/22)
// luaD_precall: enter a function call: a Lua function gets its frame (returns NULL for luaV_execute), a C
// function runs here (returns its first result).
#include "decls/data/lua.h"

// equiv-conv: FUN_00215710 esi edi
extern "C" LuaVMTObject* __cdecl FUN_00215710(LuaVMState* L, LuaVMTObject* func);
// equiv-conv: FUN_002155f0 edx esi stack
extern "C" LuaVMTObject* __cdecl FUN_002155f0(LuaVMTObject* base, LuaVMState* L, int nfixargs);
extern "C" void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
extern "C" void __cdecl FUN_00215410(LuaVMState* L, int newsize);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_00215520(LuaVMState* L, int event, int line);

extern "C" LuaVMTObject* __cdecl FUN_00215790(LuaVMState* L, LuaVMTObject* func) {
    int funcr = (int)((char*)func - (char*)L->stack);
    if (func->tt != LUAVM_TFUNCTION)
        func = FUN_00215710(L, func);
    if (L->ci + 1 == L->end_ci) {
        unsigned short n = L->size_ci;
        if (n > 0x1000)
            FUN_002152b0(L, 5);
        FUN_00215410(L, (int)(n * 2));
        if (L->size_ci > 0x1000)
            FUN_00214a90(L, "stack overflow");
    }
    LuaVMClosure* cl = (LuaVMClosure*)func->value.gc;
    if (!cl->c.isC) {
        LuaVMProto* p = cl->l.p;
        if (p->is_vararg)
            FUN_002155f0(func + 1, L, p->numparams);
        int n = p->maxstacksize;
        if ((char*)L->stack_last - (char*)L->top <= n * (int)sizeof(LuaVMTObject))
            FUN_00215460(L, n);
        LuaVMCallInfo* ci = L->ci + 1;
        L->ci = ci;
        ci->base = (LuaVMTObject*)((char*)L->stack + funcr) + 1;
        L->base = L->ci->base;
        ci->top = L->base + p->maxstacksize;
        ci->savedpc = p->code;
        ci->tailcalls = 0;
        LuaVMTObject* t = L->top;
        while (t < ci->top) {
            t->tt = LUAVM_TNIL;
            t++;
        }
        L->top = ci->top;
        return 0;
    }
    if ((char*)L->stack_last - (char*)L->top <= 20 * (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 20);
    LuaVMCallInfo* ci = L->ci + 1;
    L->ci = ci;
    ci->base = (LuaVMTObject*)((char*)L->stack + funcr) + 1;
    L->base = L->ci->base;
    ci->top = L->top + 20;
    if (L->hookmask & 1)
        FUN_00215520(L, 0, -1);
    LuaVMClosure* c = (LuaVMClosure*)L->base[-1].value.gc;
    int n = c->c.f(L);
    return L->top - n;
}
