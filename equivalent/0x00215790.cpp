// STATUS: equivalent (tools/equiv.py level 3: 103 inputs, branch coverage 22/22)
// FUN_00215790 @ 0x00215790
// FUN_00215790 @ 0x00215790
#include "compat/ptr.h"
struct lua_State_215790;

struct TObject_215790 {
    int tt;
    void* value;
};

struct CallInfo_215790 {
    TObject_215790* base;
    TObject_215790* top;
    const void* savedpc;
    int tailcalls;
};

struct Proto_215790 {
    char pad00[0xc];
    const void* code;
    char pad10[0x45 - 0x10];
    unsigned char numparams;
    unsigned char is_vararg;
    unsigned char maxstacksize;
};

struct Closure_215790 {
    char pad00[6];
    unsigned char isC;
    char pad07[5];
    union {
        Proto_215790* p;
        int (__cdecl *f)(lua_State_215790*);
    } u;
};

struct lua_State_215790 {
    char pad00[8];
    TObject_215790* top;
    TObject_215790* base;
    char pad10[4];
    CallInfo_215790* ci;
    TObject_215790* stack_last;
    TObject_215790* stack;
    char pad20[4];
    CallInfo_215790* end_ci;
    char pad28[4];
    unsigned short size_ci;
    char pad2e[2];
    unsigned char hookmask;
};

// equiv-conv: FUN_00215710 esi edi
TObject_215790* FUN_00215710(lua_State_215790* L, TObject_215790* func);
// equiv-conv: FUN_002155f0 edx esi stack
void FUN_002155f0(TObject_215790* base, lua_State_215790* L, int numparams);
void FUN_002152b0(lua_State_215790* L, int code);
void FUN_00215410(lua_State_215790* L, int newsize);
void FUN_00214a90(lua_State_215790* L, const char* fmt, ...);
void FUN_00215460(lua_State_215790* L, int n);
void FUN_00215520(lua_State_215790* L, int a, int b);

TObject_215790* FUN_00215790(lua_State_215790* L, TObject_215790* func)
{
    hulk_intptr funcr = (char*)func - (char*)L->stack;
    if (func->tt != 6)
        func = FUN_00215710(L, func);
    if (L->ci + 1 == L->end_ci) {
        unsigned short n = L->size_ci;
        if (n > 0x1000)
            FUN_002152b0(L, 5);
        FUN_00215410(L, n * 2);
        if (L->size_ci > 0x1000)
            FUN_00214a90(L, "stack overflow");
    }
    Closure_215790* cl = (Closure_215790*)func->value;
    if (!cl->isC) {
        Proto_215790* p = cl->u.p;
        if (p->is_vararg)
            FUN_002155f0(func + 1, L, p->numparams);
        int n = p->maxstacksize;
        if ((char*)L->stack_last - (char*)L->top <= n * 8)
            FUN_00215460(L, n);
        CallInfo_215790* ci = L->ci + 1;
        L->ci = ci;
        ci->base = (TObject_215790*)((char*)L->stack + funcr + 8);
        L->base = L->ci->base;
        ci->top = L->base + p->maxstacksize;
        ci->savedpc = p->code;
        ci->tailcalls = 0;
        TObject_215790* t = L->top;
        while (t < ci->top) {
            t->tt = 0;
            t++;
        }
        L->top = ci->top;
        return 0;
    }
    if ((char*)L->stack_last - (char*)L->top <= 0xa0)
        FUN_00215460(L, 0x14);
    CallInfo_215790* ci = L->ci + 1;
    L->ci = ci;
    ci->base = (TObject_215790*)((char*)L->stack + funcr + 8);
    L->base = L->ci->base;
    ci->top = (TObject_215790*)((char*)L->top + 0xa0);
    if (L->hookmask & 1)
        FUN_00215520(L, 0, -1);
    Closure_215790* c = (Closure_215790*)L->base[-1].value;
    int n = c->u.f(L);
    return (TObject_215790*)((char*)L->top - n * 8);
}
