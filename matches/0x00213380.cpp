// lua_pushlstring: push a new string of len bytes (a GC step first when due).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)FUN_00219430(L, s, len);
    o->tt = LUAVM_TSTRING;
    L->top++;
}
