// STATUS: equivalent (tools/equiv.py level 3: 138 inputs, branch coverage 6/6)
// FUN_002134a0 @ 0x002134a0
struct TObject_2134a0 {
    int tt;                 // 0x00
    void* value;            // 0x04
};

struct GlobalState_2134a0 {
    char pad0[0x48];
    unsigned int GCthreshold;   // 0x48
    unsigned int nblocks;       // 0x4c
};

struct lua_State_2134a0 {
    char pad0[8];
    TObject_2134a0* top;           // 0x08
    char pad0c[4];
    GlobalState_2134a0* l_G;       // 0x10
};

struct CClosure {
    char pad0[0xc];
    int (__cdecl *f)(lua_State_2134a0*);   // 0x0c
    TObject_2134a0 upvalue[1];     // 0x10
};

void __cdecl FUN_00217440(lua_State_2134a0* L);
CClosure* __cdecl FUN_00219520(lua_State_2134a0* L, int n);

// lua_pushcclosure
void FUN_002134a0(lua_State_2134a0* L, int (__cdecl *fn)(lua_State_2134a0*), int n)
{
    if (L->l_G->nblocks >= L->l_G->GCthreshold)
        FUN_00217440(L);
    CClosure* cl = FUN_00219520(L, n);
    cl->f = fn;
    L->top -= n;
    while (n--)
        cl->upvalue[n] = L->top[n];
    L->top->value = cl;
    L->top->tt = 6;
    L->top++;
}
