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
extern "C" void __cdecl FUN_003390d0(LuaVMState*, const char*, const void*, int);
extern void __cdecl FUN_001d07b0(LuaVMState*);
extern "C" void __cdecl FUN_002134a0(LuaVMState*, LuaVMCFunction, int);
extern "C" void __cdecl FUN_00213790(LuaVMState*, int, const char*);
struct ScriptHandler_1d3c90 {
    int FUN_001d1740(LuaVMState*);
    int target(LuaVMState**);
};
int ScriptHandler_1d3c90::target(LuaVMState** state) {
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
    FUN_003390d0(*state, 0, (const void*)DAT_00422458, 0);
    FUN_00212d80(*state, -2);
    FUN_001d07b0(*state);
    LuaVMState* saved = *state;
    FUN_002134a0(saved, FUN_001d2000, 0);
    FUN_00213790(saved, -10001, "debug");
    FUN_002134a0(saved, FUN_001d2020, 0);
    FUN_00213790(saved, -10001, "cdebug");
    return FUN_001d1740(*state);
}
