// luaB_getn
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00339d70(LuaVMState*, int, int);
extern "C" int __cdecl FUN_003392c0(LuaVMState*, int);
extern "C" void __cdecl FUN_00213360(LuaVMState*, int);
extern "C" int __cdecl FUN_0033adf0(LuaVMState* p) {
    FUN_00339d70(p, 1, 5);
    int x = FUN_003392c0(p, 1);
    FUN_00213360(p, x);
    return 1;
}
