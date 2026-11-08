#include "decls/data/lua.h"
// b: a vector passed by value (FUN_001d0870 copies its three words).
struct Vec3_1d1e50 {
    float x, y, z;
};
struct Obj_1d1e50 {
    char pad[8];
    LuaVMState* L;  // 0x08
    bool FUN_001d1e50(const char* a, Vec3_1d1e50 b);
};
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
int __cdecl FUN_001d0870(LuaVMState* L, unsigned int* vec);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
bool Obj_1d1e50::FUN_001d1e50(const char* a, Vec3_1d1e50 b) {
    FUN_002133d0(L, a);
    FUN_001d0870(L, (unsigned int*)&b);
    FUN_00213800(L, -3);
    return true;
}
