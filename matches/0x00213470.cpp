// lua_pushfstring: push the formatted string (a GC step first when due).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217440(LuaVMState* L);
extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp);

extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...) {
    LuaVMGlobal* g = L->l_G;
    if (g->totalbytes >= g->GCthreshold)
        FUN_00217440(L);
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, fmt);
    return FUN_002160c0(L, fmt, args);
#else
    return FUN_002160c0(L, fmt, (char*)(&fmt + 1));
#endif
}
