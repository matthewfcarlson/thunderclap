// lua_rawget: replace the key on top with t[key] for the table at idx (no metamethods).
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" const LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key);

extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx) {
    LuaVMTObject* t = FUN_00212bb0(idx, L);
    const LuaVMTObject* v = FUN_00219e90((LuaVMTable*)t->value.gc, L->top - 1);
    LuaVMTObject* o = L->top - 1;
    o->tt = v->tt;
    o->value = v->value;
}
