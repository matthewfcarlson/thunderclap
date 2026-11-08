// luaB_rawequal
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00213010(LuaVMState* L, int index1, int index2);
extern "C" void __cdecl FUN_00213520(LuaVMState* L, int b);

extern "C" int __cdecl FUN_0033dbe0(LuaVMState* L) {
    FUN_00339dc0(L, 1);
    FUN_00339dc0(L, 2);
    int x = FUN_00213010(L, 1, 2);
    FUN_00213520(L, x);
    return 1;
}
