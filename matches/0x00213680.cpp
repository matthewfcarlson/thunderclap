// lua_createtable: push a new table with narray array slots and room for nrec hash entries.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" int __cdecl FUN_00215f70(unsigned int x);
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash);

extern "C" void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    LuaVMTObject* o = L->top;
    int lnhash = FUN_00215f70(nrec);
    o->value.gc = (LuaVMGCObject*)FUN_00219cc0(L, narray, lnhash + 1);
    o->tt = LUAVM_TTABLE;
    L->top++;
}
