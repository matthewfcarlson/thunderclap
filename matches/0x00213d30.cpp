// lua_newuserdata: push a new full userdata of size bytes; returns its block (a GC step first when due).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" LuaVMUdata* __cdecl FUN_002194d0(LuaVMState* L, unsigned int s);

extern "C" void* __cdecl FUN_00213d30(LuaVMState* L, unsigned int size) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    LuaVMUdata* u = FUN_002194d0(L, size);
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)u;
    o->tt = LUAVM_TUSERDATA;
    L->top++;
    return u + 1;
}
