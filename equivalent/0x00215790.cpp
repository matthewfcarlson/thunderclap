// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 22/22)
// FUN_00215790 @ 0x00215790
struct lua_State;

struct TObject {
    int tt;
    void* value;
};

struct CallInfo {
    TObject* base;
    TObject* top;
    const void* savedpc;
    int tailcalls;
};

struct Proto {
    char pad00[0xc];
    const void* code;
    char pad10[0x45 - 0x10];
    unsigned char numparams;
    unsigned char is_vararg;
    unsigned char maxstacksize;
};

struct Closure {
    char pad00[6];
    unsigned char isC;
    char pad07[5];
    union {
        Proto* p;
        int (__cdecl *f)(lua_State*);
    } u;
};

struct lua_State {
    char pad00[8];
    TObject* top;
    TObject* base;
    char pad10[4];
    CallInfo* ci;
    TObject* stack_last;
    TObject* stack;
    char pad20[4];
    CallInfo* end_ci;
    char pad28[4];
    unsigned short size_ci;
    char pad2e[2];
    unsigned char hookmask;
};

// equiv-conv: FUN_00215710 esi edi
TObject* FUN_00215710(lua_State* L, TObject* func);
// equiv-conv: FUN_002155f0 esi edx stack
void FUN_002155f0(lua_State* L, TObject* base, int numparams);
void FUN_002152b0(lua_State* L, int code);
void FUN_00215410(lua_State* L, int newsize);
void FUN_00214a90(lua_State* L, const char* fmt, ...);
void FUN_00215460(lua_State* L, int n);
void FUN_00215520(lua_State* L, int a, int b);

TObject* FUN_00215790(lua_State* L, TObject* func)
{
    int funcr = (char*)func - (char*)L->stack;
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
    Closure* cl = (Closure*)func->value;
    if (!cl->isC) {
        Proto* p = cl->u.p;
        if (p->is_vararg)
            FUN_002155f0(L, func + 1, p->numparams);
        int n = p->maxstacksize;
        if ((char*)L->stack_last - (char*)L->top <= n * 8)
            FUN_00215460(L, n);
        CallInfo* ci = L->ci + 1;
        L->ci = ci;
        ci->base = (TObject*)((char*)L->stack + funcr + 8);
        L->base = L->ci->base;
        ci->top = L->base + p->maxstacksize;
        ci->savedpc = p->code;
        ci->tailcalls = 0;
        TObject* t = L->top;
        while (t < ci->top) {
            t->tt = 0;
            t++;
        }
        L->top = ci->top;
        return 0;
    }
    if ((char*)L->stack_last - (char*)L->top <= 0xa0)
        FUN_00215460(L, 0x14);
    CallInfo* ci = L->ci + 1;
    L->ci = ci;
    ci->base = (TObject*)((char*)L->stack + funcr + 8);
    L->base = L->ci->base;
    ci->top = (TObject*)((char*)L->top + 0xa0);
    if (L->hookmask & 1)
        FUN_00215520(L, 0, -1);
    Closure* c = (Closure*)L->base[-1].value;
    int n = c->u.f(L);
    return (TObject*)((char*)L->top - n * 8);
}
