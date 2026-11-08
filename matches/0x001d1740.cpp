#include "decls/data/game/global.h"
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec);
extern "C" void __cdecl FUN_00213800(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213790(LuaVMState* L, int idx, const char* k);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
// A ScriptHandler member (0x001d3c90 calls it with ecx = the handler); `this` is unused. The original returns
// nothing (eax is what lua_settable left; 0x001d4830 declares the caller 0x001d3c90 void).
struct ScriptHandler_1d3c90 {
    void FUN_001d1740(LuaVMState* L);
};
void ScriptHandler_1d3c90::FUN_001d1740(LuaVMState* L) {
    FUN_002133d0(L, DAT_004c5cf8);
    FUN_00213680(L, 0, 0);
    FUN_00213800(L, -10000);
    FUN_00212ed0(L, -10000);
    FUN_00213790(L, -10001, "HC_REGISTRY");
    FUN_00213380(L, "context", 7);
    FUN_00213680(L, 0, 0);
    FUN_00213380(L, "event", 5);
    FUN_00213680(L, 0, 0);
    FUN_00213800(L, -3);
    FUN_00213800(L, -10001);
}
