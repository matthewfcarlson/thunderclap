// lua_rawset: t[k] = v for the table at idx with k, v the two top values (no metamethods; the write barrier); pops both.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" LuaVMTObject* __cdecl FUN_00219ef0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    LuaVMTObject* top = L->top;
    LuaVMTObject* slot = FUN_00219ef0(L, (LuaVMTable*)t->value.gc, top - 2);
    slot->tt = top[-1].tt;
    slot->value = top[-1].value;
    LuaVMTObject* r = L->top;
    if (r[-1].tt >= LUAVM_TSTRING && (r[-1].value.gc->marked & 3) && (t->value.gc->marked & 4))
        FUN_00217100(L, t->value.gc, r[-1].value.gc);
    L->top -= 2;
}
