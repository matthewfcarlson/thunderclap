// luaB_assert
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00213160(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00339e60(LuaVMState* L, int narg, const char* def, unsigned int* len);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);

extern "C" int __cdecl FUN_0033e110(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    if (FUN_00213160(L, 1) == 0)
        return FUN_00338e20(L, "%s", FUN_00339e60(L, 2, "assertion failed!", 0));
    FUN_00212d80(L, 1);
    return 1;
}
