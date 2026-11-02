// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// FUN_002155f0 @ 0x002155f0
// Lua 5.0 ldo.c adjust_varargs(): pads missing fixed arguments with nil and moves the extra
// arguments into a new `arg' table (with the count in field `n').
#include "compat/ptr.h"
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

extern "C" void __cdecl FUN_00215460(void *, int);
extern "C" void * __cdecl FUN_00219cc0(void *, void *, void *);
extern TObject_2155f0 *__cdecl FUN_00219f60(lua_State_2155f0 *L, Table *t, int key);
extern TString *__cdecl FUN_00219430(lua_State_2155f0 *L, const char *str, unsigned int len);
extern TObject_2155f0 *__cdecl FUN_0021a500(lua_State_2155f0 *L, Table *t, TString *key);

// equiv-conv: FUN_002155f0 edx esi stack
extern "C" void *FUN_002155f0(void *base, void *L, int nfixargs)
{
    hulk_intptr actual = ((lua_State_2155f0 *)L)->top - ((TObject_2155f0 *)base);
    if (actual < nfixargs) {
        hulk_intptr missing = nfixargs - actual;
        if ((char *)((lua_State_2155f0 *)L)->stack_last - (char *)((lua_State_2155f0 *)L)->top <= missing * (int)sizeof(TObject_2155f0))
            FUN_00215460((lua_State_2155f0 *)((lua_State_2155f0 *)L), (hulk_intptr)missing);
        actual += missing;
        do {
            ((lua_State_2155f0 *)L)->top->tt = 0;
            ((lua_State_2155f0 *)L)->top++;
        } while (--missing);
    }
    actual -= nfixargs;

    Table *htab = ((Table *)FUN_00219cc0((lua_State_2155f0 *)((lua_State_2155f0 *)L), (void *)(hulk_uintptr)(hulk_intptr)actual, (void *)(hulk_uintptr)(int)1));
    for (int i = 0; i < actual; i++) {
        TObject_2155f0 *src = ((lua_State_2155f0 *)L)->top - actual + i;
        TObject_2155f0 *dst = FUN_00219f60(((lua_State_2155f0 *)L), htab, i + 1);
        *dst = *src;
    }
    TObject_2155f0 *slot = FUN_0021a500(((lua_State_2155f0 *)L), htab, FUN_00219430(((lua_State_2155f0 *)L), "n", 1));
    slot->tt = 3;
    slot->value.n = (float)actual;
    ((lua_State_2155f0 *)L)->top -= actual;
    ((lua_State_2155f0 *)L)->top->value.p = htab;
    ((lua_State_2155f0 *)L)->top->tt = 5;
    if ((char *)((lua_State_2155f0 *)L)->stack_last - (char *)((lua_State_2155f0 *)L)->top <= (int)sizeof(TObject_2155f0))
        FUN_00215460((lua_State_2155f0 *)((lua_State_2155f0 *)L), 1);
    ((lua_State_2155f0 *)L)->top++;
    return (TObject_2155f0 *)(((lua_State_2155f0 *)L)->top);
}
