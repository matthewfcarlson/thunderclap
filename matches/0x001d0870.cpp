#include "decls/data/lua.h"
extern "C" void* __cdecl FUN_00213d30(LuaVMState*, unsigned int);
extern "C" void __cdecl FUN_00338f30(LuaVMState*, const char*);
extern "C" void __cdecl FUN_002138e0(LuaVMState*, int);

int __cdecl FUN_001d0870(LuaVMState* L, unsigned int* vec) {
    unsigned int* dst = (unsigned int*)FUN_00213d30(L, 0xc);
    FUN_00338f30(L, "Vector");
    FUN_002138e0(L, -2);
    dst[0] = vec[0];
    dst[1] = vec[1];
    dst[2] = vec[2];
    return 1;
}
