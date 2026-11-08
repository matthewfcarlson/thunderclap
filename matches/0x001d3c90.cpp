#include "decls/data/game/global.h"
#include "decls/data/lua.h"
// the Lua state's allocator (0x001d0990: unused context, block, old size, new size)
extern "C" void* __cdecl FUN_001d0990(void*, void*, unsigned int, unsigned int);
extern int __cdecl FUN_001d2000(LuaVMState*);
extern "C" int __cdecl FUN_001d2020(LuaVMState*);
extern "C" void __cdecl FUN_002151e0(LuaVMState*);
extern "C" LuaVMState* __cdecl FUN_002150e0(LuaVMAlloc, void*);
extern "C" void __cdecl FUN_0033eb30(LuaVMState*);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" void __cdecl FUN_0033d6c0(LuaVMState*);
extern "C" void __cdecl FUN_0033bca0(LuaVMState*);
extern "C" void __cdecl FUN_0033b560(LuaVMState*);
extern "C" void __cdecl FUN_0033ac90(LuaVMState*);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*, int);
extern "C" void __cdecl FUN_003390d0(LuaVMState* L, const char* libname, const LuaVMReg* l, int nup);
extern "C" int __cdecl FUN_001d07b0(LuaVMState* L);
extern "C" void __cdecl FUN_002134a0(LuaVMState*, LuaVMCFunction, int);
extern "C" void __cdecl FUN_00213790(LuaVMState*, int, const char*);
struct ScriptHandler_1d3c90 {
#if defined(HULK_PTR64)
    void FUN_001d1740(LuaVMState*);  // (the definition's type: it returns nothing)
#else
    int FUN_001d1740(LuaVMState*);   // (the original returns what 0x001d1740 left in eax)
#endif
    int FUN_001d3c90(LuaVMState**);
};
int ScriptHandler_1d3c90::FUN_001d3c90(LuaVMState** state) {
    if (*state) {
        FUN_002151e0(*state);
        *state = 0;
    }
    *state = FUN_002150e0(FUN_001d0990, 0);
    FUN_0033eb30(*state);
    FUN_00212d80(*state, 0);
    FUN_0033d6c0(*state);
    FUN_00212d80(*state, 0);
    FUN_0033bca0(*state);
    FUN_00212d80(*state, 0);
    FUN_0033b560(*state);
    FUN_00212d80(*state, 0);
    FUN_0033ac90(*state);
    FUN_00212d80(*state, 0);
    FUN_00212ed0(*state, -10001);
    FUN_003390d0(*state, 0, (const LuaVMReg*)DAT_00422458, 0);
    FUN_00212d80(*state, -2);
    FUN_001d07b0(*state);
    LuaVMState* saved = *state;
    FUN_002134a0(saved, FUN_001d2000, 0);
    FUN_00213790(saved, -10001, "debug");
    FUN_002134a0(saved, FUN_001d2020, 0);
    FUN_00213790(saved, -10001, "cdebug");
#if defined(HULK_PTR64)
    FUN_001d1740(*state);
    return 0;  // (no caller reads it: 0x001d4830 calls this as void)
#else
    return FUN_001d1740(*state);
#endif
}
