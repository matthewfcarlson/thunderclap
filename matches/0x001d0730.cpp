// FUN_001d0730 @ 0x001d0730
// 0x001d0730: Lua C function: array[(int)arg] = number (arg 3), with a subscript error
#include "decls/data/lua.h"
extern "C" void* __cdecl FUN_00213260(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int a, int b);
extern "C" void __cdecl FUN_002136d0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213600(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx);
extern "C" float __cdecl FUN_002130e0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* msg, unsigned int len);
extern "C" void __cdecl FUN_00213c40(LuaVMState* L);

extern "C" int FUN_001d0730(LuaVMState* L)
{
    float* array = (float*)FUN_00213260(L, 1);
    FUN_00339d70(L, 3, 3);
    FUN_002136d0(L, 1);
    FUN_00212ed0(L, 2);
    FUN_00213600(L, -2);
    if (FUN_00212f70(L, -1) != 0) {
        int index = (int)FUN_002130e0(L, -1);
        array[index] = FUN_002130e0(L, 3);
        return 0;
    }
    FUN_00213380(L, "invalid subscript in assignment", 0x1f);
    FUN_00213c40(L);
    return 0;
}
