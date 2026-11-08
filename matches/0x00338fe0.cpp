// luaL_checkstack
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212c50(LuaVMState* L, int size);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00338fe0(LuaVMState* L, int space, const char* mes) {
    if (!FUN_00212c50(L, space))
        FUN_00338e20(L, "stack overflow (%s)", mes);
}
