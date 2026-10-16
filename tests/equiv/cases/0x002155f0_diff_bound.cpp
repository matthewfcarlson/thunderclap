// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_002155f0 @ 0x002155f0
// Lua 5.0 ldo.c adjust_varargs(): pads missing fixed arguments with nil and moves the extra
// arguments into a new `arg' table (with the count in field `n').
struct TObject_2155f0 {
    int tt;
    union {
        void *p;
        float n;
    } value;
};

struct Table;
struct TString;

struct lua_State_2155f0 {
    char pad00[8];
    TObject_2155f0 *top;
    char pad0c[0xc];
    TObject_2155f0 *stack_last;
};

extern void __cdecl FUN_00215460(lua_State_2155f0 *L, int n);
extern Table *__cdecl FUN_00219cc0(lua_State_2155f0 *L, int narray, int lnhash);
extern TObject_2155f0 *__cdecl FUN_00219f60(lua_State_2155f0 *L, Table *t, int key);
extern TString *__cdecl FUN_00219430(lua_State_2155f0 *L, const char *str, unsigned int len);
extern TObject_2155f0 *__cdecl FUN_0021a500(lua_State_2155f0 *L, Table *t, TString *key);

// equiv-conv: FUN_002155f0 edx esi stack
TObject_2155f0 *FUN_002155f0(TObject_2155f0 *base, lua_State_2155f0 *L, int nfixargs)
{
    int actual = L->top - base;
    if (actual < nfixargs) {
        int missing = nfixargs - actual;
        if ((char *)L->stack_last - (char *)L->top <= missing * (int)sizeof(TObject_2155f0))
            FUN_00215460(L, missing);
        actual += missing;
        do {
            L->top->tt = 0;
            L->top++;
        } while (--missing);
    }
    actual -= nfixargs;

    Table *htab = FUN_00219cc0(L, actual, 1);
    for (int i = 0; i < actual; i++) {
        TObject_2155f0 *src = L->top - actual + i;
        TObject_2155f0 *dst = FUN_00219f60(L, htab, i + 1);
        *dst = *src;
    }
    TObject_2155f0 *slot = FUN_0021a500(L, htab, FUN_00219430(L, "n", 1));
    slot->tt = 3;
    slot->value.n = (float)actual;
    L->top -= actual;
    L->top->value.p = htab;
    L->top->tt = 5;
    if ((char *)L->stack_last - (char *)L->top <= (int)sizeof(TObject_2155f0))
        FUN_00215460(L, 1);
    L->top++;
    return L->top;
}
