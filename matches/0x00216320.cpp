// luaO_pushfstring.
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp);

extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, fmt);
    return FUN_002160c0(L, fmt, args);
#else
    return FUN_002160c0(L, fmt, (char*)(&fmt + 1));
#endif
}
