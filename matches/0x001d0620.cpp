#include "decls/data/lua.h"
extern "C" float __cdecl FUN_00339f40(LuaVMState* L, int narg, float def);
extern "C" void* __cdecl FUN_00213d30(LuaVMState* L, unsigned int size);
extern "C" void __cdecl FUN_00338f30(LuaVMState* L, const char* tname);
extern "C" int __cdecl FUN_002138e0(LuaVMState* L, int objindex);
extern "C" int __cdecl FUN_001d0620(LuaVMState* L) {
    float x = FUN_00339f40(L, 1, 0.0f);
    float y = FUN_00339f40(L, 2, 0.0f);
    float z = FUN_00339f40(L, 3, 0.0f);
    float* v = (float*)FUN_00213d30(L, 12);
    FUN_00338f30(L, "Vector");
    FUN_002138e0(L, -2);
    v[0] = x;
    v[1] = y;
    v[2] = z;
    return 1;
}
