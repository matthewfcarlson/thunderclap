// STATUS: equivalent (tools/equiv.py level 3: 2866 inputs, branch coverage 2/2)
// callTMres: call the metamethod pushed at the top (3 slots) for one result and store it in res.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);

// equiv-conv: FUN_00217790 ecx eax
extern "C" void __cdecl FUN_00217790(LuaVMState* L, LuaVMTObject* res) {
    hulk_intptr result = (char*)res - (char*)L->stack;  // savestack
    if ((char*)L->stack_last - (char*)L->top <= 3 * (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 3);
    LuaVMTObject* func = L->top;
    L->top = func + 3;
    FUN_002159e0(L, func, 1);
    LuaVMTObject* src = L->top - 1;
    L->top = src;
    res = (LuaVMTObject*)((char*)L->stack + result);  // restorestack
    LUAVM_SETOBJ(res, src);
}
