#include "decls/data/lua.h"
float gZero_1d1010 = 0.0f;
extern "C" void __cdecl FUN_002135a0(LuaVMState* L, int idx, const char* k);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx);
float __stdcall FUN_001d1010(const char* name, LuaVMState* L) {
    if (name == 0)
        return gZero_1d1010;
    FUN_002135a0(L, -10001, name);
    int r = FUN_00212f00(L, -1);
    if (r != 3) {
        FUN_00212d80(L, -2);
        return gZero_1d1010;
    }
    float x = FUN_002130e0(L, -1);
    FUN_00212d80(L, -2);
    return x;
}
