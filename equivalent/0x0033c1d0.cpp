// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_0033c1d0 @ 0x0033c1d0
// cl-flags: /GS

// Lua 5.0 str_dump
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);                 // luaL_checktype
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* B);                  // luaL_buffinit
extern "C" int __cdecl FUN_00213b60(LuaVMState* L, LuaVMWriter writer, void* data);   // lua_dump
extern "C" int __cdecl FUN_0033c1b0(LuaVMState* L, const void* p, unsigned int size, void* ud);  // writer
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);             // luaL_error
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* B);                                 // luaL_pushresult

extern "C" int __cdecl FUN_0033c1d0(LuaVMState* L) {
    LuaVMLBuffer b;
    FUN_00339d70(L, 1, LUAVM_TFUNCTION);
    FUN_00339630(L, &b);
    if (!FUN_00213b60(L, FUN_0033c1b0, &b))
        FUN_00338e20(L, "unable to dump given function");
    FUN_00339540(&b);
    return 1;
}
