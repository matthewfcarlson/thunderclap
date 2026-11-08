// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 8/8)
// luaG_errormsg: call the error handler (errfunc, else the global _TRACEBACK) on the message on top; throws.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002152b0(LuaVMState* L, int errcode);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" const LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);

extern "C" void __cdecl FUN_002149b0(LuaVMState* L) {
    const LuaVMTObject* errfunc;
    if (L->errfunc)
        errfunc = (LuaVMTObject*)((char*)L->stack + L->errfunc);
    else {
        LuaVMString* key = FUN_00219430(L, "_TRACEBACK", 10);
        errfunc = FUN_00219e50((LuaVMTable*)L->_gt.value.gc, key);
    }
    if (errfunc->tt != LUAVM_TFUNCTION)
        FUN_002152b0(L, 5);
    LuaVMTObject* top = L->top;
    top->tt = top[-1].tt;
    top->value = top[-1].value;
    top = L->top - 1;
    top->tt = errfunc->tt;
    top->value = errfunc->value;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    FUN_002159e0(L, L->top - 2, 1);
    FUN_002152b0(L, 1);
}
