// luaB_setn
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00339d70(LuaVMState*, int, int);
extern "C" int __cdecl FUN_00339f70(LuaVMState*, int);
extern "C" void __cdecl FUN_00339270(LuaVMState*, int, int);
extern "C" int __cdecl FUN_0033ae20(LuaVMState* a) {
    FUN_00339d70(a, 1, 5);
    int v = FUN_00339f70(a, 2);
    FUN_00339270(a, 1, v);
    return 0;
}
