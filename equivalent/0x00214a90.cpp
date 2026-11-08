// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// luaG_runerror: raise the formatted message with the "chunk:line:" prefix.
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp);
// equiv-conv: FUN_00214900 ebx stack
extern "C" void FUN_00214900(LuaVMState* L, const char* msg);
extern "C" void __cdecl FUN_002149b0(LuaVMState* L);

extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...)
{
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, fmt);
    const char* msg = FUN_002160c0(L, fmt, args);
#else
    const char* msg = FUN_002160c0(L, fmt, (char*)(&fmt + 1));
#endif
    FUN_00214900(L, msg);
    FUN_002149b0(L);
}
