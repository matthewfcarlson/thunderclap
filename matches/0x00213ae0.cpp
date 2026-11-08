// lua_cpcall: call the C function func with ud in protected mode.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00213a50(LuaVMState* L, void* ud);
extern "C" int __cdecl FUN_00215de0(LuaVMState* L, void(__cdecl* f)(LuaVMState*, void*), void* u, int oldtop, int ef);

extern "C" int __cdecl FUN_00213ae0(LuaVMState* L, LuaVMCFunction func, void* ud) {
    LuaVMCCallS c;
    c.func = func;
    c.ud = ud;
    return FUN_00215de0(L, FUN_00213a50, &c, (int)((char*)L->top - (char*)L->stack), 0);
}
