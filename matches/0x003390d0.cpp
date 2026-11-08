// luaL_openlib
#include "decls/data/lua.h"
extern "C" {
void __cdecl FUN_002135a0(LuaVMState*, int, const char*);
int __cdecl FUN_00212f00(LuaVMState*, int);
void __cdecl FUN_00212d80(LuaVMState*, int);
void __cdecl FUN_00213680(LuaVMState*, int, int);
void __cdecl FUN_00212ed0(LuaVMState*, int);
void __cdecl FUN_00213790(LuaVMState*, int, const char*);
void __cdecl FUN_00212e20(LuaVMState*, int);
void __cdecl FUN_002134a0(LuaVMState*, LuaVMCFunction, int);
}
extern "C" void __cdecl FUN_003390d0(LuaVMState* state, const char* name, const LuaVMReg* entries, int upvalueCount) {
    if (name) {
        FUN_002135a0(state, -10001, name);
        if (!FUN_00212f00(state, -1)) {
            FUN_00212d80(state, -2);
            FUN_00213680(state, 0, 0);
            FUN_00212ed0(state, -1);
            FUN_00213790(state, -10001, name);
        }
        FUN_00212e20(state, -1 - upvalueCount);
    }
    if (entries->name) {
        int destination = -2 - upvalueCount;
        do {
            for (int i = 0; i < upvalueCount; ++i)
                FUN_00212ed0(state, -upvalueCount);
            FUN_002134a0(state, entries->func, upvalueCount);
            FUN_00213790(state, destination, entries->name);
            ++entries;
        } while (entries->name);
    }
    FUN_00212d80(state, -1 - upvalueCount);
}
