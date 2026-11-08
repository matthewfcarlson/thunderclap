// luaB_loadfile
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339e60(LuaVMState* L, int narg, const char* def, unsigned int* len);
extern "C" int __cdecl FUN_00339800(LuaVMState* L, const char* filename);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);

extern "C" int __cdecl FUN_0033df30(LuaVMState* L) {
    const char* fname = FUN_00339e60(L, 1, 0, 0);
    int status = FUN_00339800(L, fname);
    if (status == 0)
        return 1;
    FUN_00213320(L);
    FUN_00212e20(L, -2);
    return 2;
}
