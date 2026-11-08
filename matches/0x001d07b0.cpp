#include "decls/data/game/global.h"
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00338eb0(LuaVMState* L, const char* tname);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" void __cdecl FUN_00213340(LuaVMState* L, float n);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_001d07b0(LuaVMState* L) {
    FUN_00212ed0(L, -10001);
    FUN_003390d0(L, 0, (const LuaVMReg*)&DAT_004223c8, 0);
    FUN_00212d80(L, -2);
    FUN_00338eb0(L, DAT_00422404);
    FUN_003390d0(L, 0, (const LuaVMReg*)&DAT_004223d8, 0);
    FUN_00213380(L, DAT_00421bb4, 1);
    FUN_00213340(L, 0.0f);
    FUN_00213800(L, -3);
    FUN_00213380(L, DAT_00421bb0, 1);
    FUN_00213340(L, 1.0f);
    FUN_00213800(L, -3);
    FUN_00213380(L, DAT_00421bac, 1);
    FUN_00213340(L, 2.0f);
    FUN_00213800(L, -3);
    FUN_00212d80(L, -2);
    return 0;
}
