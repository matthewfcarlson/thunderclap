// callallgcTM: the protected body of lua_close's finalizer pass (luaC_callGCTM).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00216f60(LuaVMState* L);

extern "C" void __cdecl FUN_002151d0(LuaVMState* L, void* ud) {
    FUN_00216f60(L);
}
