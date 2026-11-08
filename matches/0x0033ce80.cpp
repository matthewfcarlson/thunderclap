// string.gfind
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);
extern "C" void __cdecl FUN_002134a0(LuaVMState* L, LuaVMCFunction fn, int n);
extern "C" int __cdecl FUN_0033cdb0(LuaVMState* L);

extern "C" int __cdecl FUN_0033ce80(LuaVMState* L) {
    FUN_00339df0(L, 1, 0);
    FUN_00339df0(L, 2, 0);
    FUN_00212d80(L, 2);
    FUN_00213360(L, 0);
    FUN_002134a0(L, FUN_0033cdb0, 3);
    return 1;
}
