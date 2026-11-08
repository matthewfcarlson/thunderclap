// luaB_xpcall
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212e20(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_002139f0(LuaVMState* L, int nargs, int nresults, int errfunc);
extern "C" void __cdecl FUN_00213520(LuaVMState* L, int b);
extern "C" void __cdecl FUN_00212e60(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);

extern "C" int __cdecl FUN_0033e200(LuaVMState* L) {
    FUN_00339dc0(L, 2);
    FUN_00212d80(L, 2);
    FUN_00212e20(L, 1);
    int status = FUN_002139f0(L, 0, -1, 1);
    FUN_00213520(L, status == 0);
    FUN_00212e60(L, 1);
    return FUN_00212d70(L);
}
