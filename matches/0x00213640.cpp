// lua_rawgeti: push t[n] for the table at idx (no metamethods).
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" const LuaVMTObject* __cdecl FUN_00219dc0(LuaVMTable* t, int key);

extern "C" void __cdecl FUN_00213640(LuaVMState* L, int idx, int n) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    const LuaVMTObject* v = FUN_00219dc0((LuaVMTable*)o->value.gc, n);
    LuaVMTObject* t = L->top;
    t->tt = v->tt;
    t->value = v->value;
    L->top++;
}
