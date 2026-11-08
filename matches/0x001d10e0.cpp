#include "decls/data/lua.h"
extern "C" void __cdecl FUN_002135a0(LuaVMState*, int, const char*);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" const char* __cdecl FUN_00213190(LuaVMState*, int);
const char* __stdcall FUN_001d10e0(const char* name, LuaVMState* L) {
    FUN_002135a0(L, 0xffffd8ef, name);
    int i = FUN_00212f00(L, -1);
    if (i != 4) {
        FUN_00212d80(L, -2);
        return 0;
    }
    const char* result = FUN_00213190(L, -1);
    FUN_00212d80(L, -2);
    return result;
}
