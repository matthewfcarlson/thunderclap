// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// lundump error: "<chunk name>: <message>" on the stack, then throw LUA_ERRSYNTAX (3).
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_002160c0(LuaVMState* L, const char* fmt, char* argp);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_002152b0(LuaVMState* L, int errcode);

// C++ linkage on purpose: equiv.py's 32-bit runs pass a wrong first argument to an extern "C" variadic definition
// with a register convention (the callers' extern "C" declarations bind by the address name).
// equiv-conv: FUN_0021f800 esi stack
void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list va;
    __builtin_va_start(va, fmt);
    const char* text = FUN_002160c0(S->L, fmt, va);
#else
    const char* text = FUN_002160c0(S->L, fmt, (char*)(void*)(&fmt + 1));
#endif
    FUN_00216320(S->L, "%s: %s", S->name, text);
    FUN_002152b0(S->L, 3);
}
