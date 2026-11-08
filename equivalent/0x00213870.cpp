// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// lua_rawseti: t[n] = the top value for the table at idx (no metamethods; the write barrier); pops it.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" LuaVMTObject* __cdecl FUN_00219f60(LuaVMState* L, LuaVMTable* t, int key);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

extern "C" void __cdecl FUN_00213870(LuaVMState* L, int idx, int n) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    LuaVMTObject* val = L->top - 1;
    LuaVMTObject* slot = FUN_00219f60(L, (LuaVMTable*)t->value.gc, n);
    *slot = *val;
    if (L->top[-1].tt >= LUAVM_TSTRING) {
        LuaVMGCObject* v = L->top[-1].value.gc;
        if ((v->marked & 3) != 0) {
            LuaVMGCObject* h = t->value.gc;
            if ((h->marked & 4) != 0)
                FUN_00217100(L, h, v);
        }
    }
    L->top--;
}
