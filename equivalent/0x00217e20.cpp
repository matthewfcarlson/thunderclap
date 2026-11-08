// STATUS: equivalent (tools/equiv.py level 3: 3035 inputs, branch coverage 22/22)
// luaV_equalval: t1 == t2 for two values of one type (tables and userdata by __eq).
#include "decls/data/lua.h"

// equiv-conv: FUN_00217b60 edi esi ebx stack
extern "C" const LuaVMTObject* __cdecl FUN_00217b60(LuaVMTable* mt1, int event, LuaVMTable* mt2, LuaVMState* L);
// equiv-conv: FUN_00217750 ecx stack eax edx
extern "C" void __cdecl FUN_00217750(LuaVMState* L, const LuaVMTObject* f, const LuaVMTObject* p1,
                                     const LuaVMTObject* p2);
// equiv-conv: FUN_00217790 ecx eax
extern "C" void __cdecl FUN_00217790(LuaVMState* L, LuaVMTObject* res);

extern "C" int __cdecl FUN_00217e20(LuaVMState* L, const LuaVMTObject* t1, const LuaVMTObject* t2) {
    switch (t1->tt) {
    case LUAVM_TNIL:
        return 1;
    case LUAVM_TNUMBER:
        return t1->value.n == t2->value.n;
    case LUAVM_TTABLE:
    case LUAVM_TUSERDATA: {
        if (t1->value.gc == t2->value.gc)
            return 1;
        // a table's and a userdata's metatable (the original reads both at the one offset they share)
        LuaVMTable* mt1 = t1->tt == LUAVM_TTABLE ? ((LuaVMTable*)t1->value.gc)->metatable
                                                 : ((LuaVMUdata*)t1->value.gc)->metatable;
        LuaVMTable* mt2 = t1->tt == LUAVM_TTABLE ? ((LuaVMTable*)t2->value.gc)->metatable
                                                 : ((LuaVMUdata*)t2->value.gc)->metatable;
        const LuaVMTObject* tm = FUN_00217b60(mt1, 4, mt2, L);
        if (!tm)
            return 0;
        FUN_00217750(L, tm, t1, t2);
        FUN_00217790(L, L->top);
        const LuaVMTObject* res = L->top;
        return res->tt != LUAVM_TNIL && (res->tt != LUAVM_TBOOLEAN || res->value.b != 0);
    }
    case LUAVM_TBOOLEAN:
        return t1->value.b == t2->value.b;
    default:  // light userdata, strings, functions, threads: by the pointer (the original's 32-bit compare)
        return t1->value.p == t2->value.p;
    }
}
