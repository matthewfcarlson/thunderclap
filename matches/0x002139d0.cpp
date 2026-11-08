// f_call: the protected body of lua_pcall (luaD_call with the CallS's function and result count).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);

extern "C" void __cdecl FUN_002139d0(LuaVMState* L, void* ud) {
    LuaVMCallS* c = (LuaVMCallS*)ud;
    FUN_002159e0(L, c->func, c->nresults);
}
