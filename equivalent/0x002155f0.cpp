// STATUS: equivalent (tools/equiv.py level 3: 56 inputs, branch coverage 12/12)
// adjust_varargs: pad missing fixed arguments with nil and move the extra ones into a new `arg' table (with the
// count in field `n'), pushed in their place.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash);
extern "C" LuaVMTObject* __cdecl FUN_00219f60(LuaVMState* L, LuaVMTable* t, int key);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" LuaVMTObject* __cdecl FUN_0021a500(LuaVMState* L, LuaVMTable* t, LuaVMString* key);

// equiv-conv: FUN_002155f0 edx esi stack
extern "C" LuaVMTObject* __cdecl FUN_002155f0(LuaVMTObject* base, LuaVMState* L, int nfixargs) {
    int actual = (int)(L->top - base);
    if (actual < nfixargs) {
        int missing = nfixargs - actual;
        if ((char*)L->stack_last - (char*)L->top <= missing * (int)sizeof(LuaVMTObject))
            FUN_00215460(L, missing);
        actual += missing;
        do {
            L->top->tt = LUAVM_TNIL;
            L->top++;
        } while (--missing);
    }
    actual -= nfixargs;

    LuaVMTable* htab = FUN_00219cc0(L, actual, 1);
    for (int i = 0; i < actual; i++) {
        LuaVMTObject* src = L->top - actual + i;
        LuaVMTObject* dst = FUN_00219f60(L, htab, i + 1);
        LUAVM_SETOBJ(dst, src);
    }
    LuaVMTObject* slot = FUN_0021a500(L, htab, FUN_00219430(L, "n", 1));
    slot->tt = LUAVM_TNUMBER;
    slot->value.n = (float)actual;
    L->top -= actual;
    L->top->value.gc = (LuaVMGCObject*)htab;
    L->top->tt = LUAVM_TTABLE;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    return L->top;
}
