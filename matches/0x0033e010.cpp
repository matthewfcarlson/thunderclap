// FUN_0033e010 @ 0x0033e010
// luaB_load
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339e60(LuaVMState* L, int narg, const char* def, unsigned int* len);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339650(LuaVMState* L, int t);
extern "C" void __cdecl FUN_00339710(LuaVMState* L, int t, int ref);
extern "C" void __cdecl FUN_00213320(LuaVMState* L);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_0033df70(LuaVMState* L, void* ud, unsigned int* size);
extern "C" int __cdecl FUN_00213b20(LuaVMState* L, LuaVMReader reader, void* data, const char* chunkname);

extern "C" int __cdecl FUN_0033e010(LuaVMState* L)
{
    LuaVMLoadRefs ls;
    const char* chunkname = FUN_00339e60(L, 2, "=(load)", 0);
    FUN_00339d70(L, 1, LUAVM_TFUNCTION);
    FUN_00212d80(L, 1);
    ls.func = FUN_00339650(L, -10000);
    ls.res = -1;
    int status = FUN_00213b20(L, FUN_0033df70, &ls, chunkname);
    FUN_00339710(L, ls.func, -10000);
    FUN_00339710(L, ls.res, -10000);
    if (status == 0)
        return 1;
    FUN_00213320(L);
    FUN_00212e20(L, -2);
    return 2;
}
