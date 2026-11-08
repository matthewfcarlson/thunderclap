// lua_tostring: the string at idx (a number is converted in place); NULL otherwise. A GC step when due.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" int __cdecl FUN_00217640(LuaVMState* L, LuaVMTObject* obj);
extern "C" void __cdecl FUN_00217440(LuaVMState* L);

extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx) {
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt == LUAVM_TSTRING)
        return LUAVM_GETSTR(o->value.gc);
    const char* s = FUN_00217640(L, o) ? LUAVM_GETSTR(o->value.gc) : 0;
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    return s;
}
