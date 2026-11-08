// string.len
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);

extern "C" int __cdecl FUN_0033bd00(LuaVMState* L) {
    unsigned int l;
    FUN_00339df0(L, 1, &l);
    FUN_00213360(L, (int)l);
    return 1;
}
