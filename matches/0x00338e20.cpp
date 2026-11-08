// luaL_error: "where" + the formatted message, then lua_error.
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00338d90(LuaVMState* L, int level);
extern "C" const char* __cdecl FUN_00213440(LuaVMState* L, const char* fmt, char* argp);
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n);
extern "C" int __cdecl FUN_00213c40(LuaVMState* L);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...) {
    FUN_00338d90(L, 1);
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, fmt);
    FUN_00213440(L, fmt, (char*)args);
#else
    FUN_00213440(L, fmt, (char*)&fmt + sizeof(fmt));
#endif
    FUN_00213c90(L, 2);
    return FUN_00213c40(L);
}
