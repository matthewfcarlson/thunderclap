// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 8/8)
// tryfuncTM: a non-function call goes through the value's __call metamethod (inserted below the arguments).
#include "decls/data/lua.h"

// equiv-conv: FUN_002175b0 stack stack stack
extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event);
extern "C" void __cdecl FUN_00214c90(LuaVMState* L, const LuaVMTObject* o, const char* op);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);

// equiv-conv: FUN_00215710 esi edi
extern "C" LuaVMTObject* __cdecl FUN_00215710(LuaVMState* L, LuaVMTObject* func) {
    const LuaVMTObject* tm = FUN_002175b0(L, func, 14);
    int funcr = (int)((char*)func - (char*)L->stack);
    if (tm->tt != LUAVM_TFUNCTION)
        FUN_00214c90(L, func, "call");
    for (LuaVMTObject* p = L->top; p > func; p--)
        LUAVM_SETOBJ(p, p - 1);
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    L->top++;
    func = (LuaVMTObject*)((char*)L->stack + funcr);
    LUAVM_SETOBJ(func, tm);
    return func;
}
