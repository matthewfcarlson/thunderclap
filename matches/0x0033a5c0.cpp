// db_setupvalue
#include "decls/data/lua.h"
extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00339d70(LuaVMState* L, int narg, int t);
extern "C" int __cdecl FUN_00212f40(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213e50(LuaVMState* L, int funcindex, int n);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_0033a5c0(LuaVMState* self) {
    int edi;
    FUN_00339dc0(self, 3);
    edi = FUN_00339f70(self, 2);
    FUN_00339d70(self, 1, 6);
    if (FUN_00212f40(self, 1) != 0)
        return 0;
    const char* r = FUN_00213e50(self, 1, edi);
    if (r == 0)
        return 0;
    FUN_002133d0(self, r);
    FUN_00212e20(self, -1);
    return 1;
}
