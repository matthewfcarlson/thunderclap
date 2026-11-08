// lua_pushvfstring: push the formatted string (a GC step first when due).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp);

extern "C" const char* __cdecl FUN_00213440(LuaVMState* L, const char* fmt, char* argp) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
    return FUN_002160c0(L, fmt, argp);
}
