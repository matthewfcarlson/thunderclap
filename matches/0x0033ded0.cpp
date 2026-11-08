// luaB_loadstring
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" const char* __cdecl FUN_00339e60(LuaVMState* L, int narg, const char* def, unsigned int* len);
extern "C" int __cdecl FUN_00339a60(LuaVMState* L, const char* buff, unsigned int size, const char* name);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);

extern "C" int __cdecl FUN_0033ded0(LuaVMState* L) {
    unsigned int l;
    const char* s = FUN_00339df0(L, 1, &l);
    const char* chunkname = FUN_00339e60(L, 2, s, 0);
    if (!FUN_00339a60(L, s, l, chunkname))
        return 1;
    FUN_00213320(L);
    FUN_00212e20(L, -2);
    return 2;
}
