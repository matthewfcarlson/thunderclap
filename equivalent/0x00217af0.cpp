// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 4/4)
// call_binTM: call the event's metamethod of p1 (else p2) on p1, p2 into res; 0 when there is none.
#include "decls/data/lua.h"

extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event);
// equiv-conv: FUN_00217790 ecx eax
extern "C" void __cdecl FUN_00217790(LuaVMState* L, LuaVMTObject* res);

// equiv-conv: FUN_00217af0 esi ebx edi stack stack
extern "C" int __cdecl FUN_00217af0(LuaVMState* L, const LuaVMTObject* p1, const LuaVMTObject* p2, LuaVMTObject* res,
                                    int event) {
    const LuaVMTObject* tm = FUN_002175b0(L, p1, event);
    if (tm->tt == LUAVM_TNIL)
        tm = FUN_002175b0(L, p2, event);
    if (tm->tt != LUAVM_TFUNCTION)
        return 0;
    L->top->tt = LUAVM_TFUNCTION;
    L->top->value = tm->value;
    LUAVM_SETOBJ(L->top + 1, p1);
    LUAVM_SETOBJ(L->top + 2, p2);
    FUN_00217790(L, res);
    return 1;
}
