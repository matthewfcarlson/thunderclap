// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 10/10)
// call_orderTM: the truth of an order metamethod shared by p1 and p2, or -1 when there is none.
#include "decls/data/lua.h"

extern "C" const LuaVMTObject* __cdecl FUN_002175b0(LuaVMState* L, const LuaVMTObject* o, int event);
extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2);
// equiv-conv: FUN_00217790 ecx eax
extern "C" void __cdecl FUN_00217790(LuaVMState* L, LuaVMTObject* res);

// equiv-conv: FUN_00217be0 eax stack stack ebx
extern "C" int __cdecl FUN_00217be0(LuaVMState* L, const LuaVMTObject* p1, int event, const LuaVMTObject* p2) {
    const LuaVMTObject* tm1 = FUN_002175b0(L, p1, event);
    if (tm1->tt == LUAVM_TNIL)
        return -1;
    const LuaVMTObject* tm2 = FUN_002175b0(L, p2, event);
    if (!FUN_00215fa0(tm1, tm2))
        return -1;

    L->top[0] = *tm1;
    L->top[1] = *p1;
    L->top[2] = *p2;
    FUN_00217790(L, L->top);

    const LuaVMTObject* r = L->top;
    if (r->tt == LUAVM_TNIL)
        return 0;
    if (r->tt == LUAVM_TBOOLEAN && r->value.b == 0)
        return 0;
    return 1;
}
