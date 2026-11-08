#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#include "gen/owners.h"

typedef unsigned int U_1d2890;
extern "C" {
void __cdecl FUN_00213380(LuaVMState*, const char*, unsigned int);
void __cdecl FUN_00213600(LuaVMState*, int);
void __cdecl FUN_002133d0(LuaVMState*, const char*);
int __cdecl FUN_00339a60(LuaVMState*, const char*, unsigned int, const char*);
int __cdecl FUN_002139f0(LuaVMState*, int, int, int);
void __cdecl FUN_00213190(LuaVMState*, int);
void __cdecl FUN_00212d80(LuaVMState*, int);
LuaVMState* __cdecl FUN_00213290(LuaVMState*, int);
void __cdecl FUN_00212e20(LuaVMState*, int);
void __cdecl FUN_00213870(LuaVMState*, int, int);
}
// state is a void* member of include/gen/owners.h Object_1d2890; a (the chunk's buffer) is an unsigned int
// parameter there: cast at the use.
U_1d2890 owners::Object_1d2890::FUN_001d2890(U_1d2890 a, U_1d2890 b, U_1d2890 c) {
    FUN_00213380((LuaVMState*)state, "coroutine", 9);
    FUN_00213600((LuaVMState*)state, -10001);
    FUN_002133d0((LuaVMState*)state, "create");
    FUN_00213600((LuaVMState*)state, -2);
    FUN_00339a60((LuaVMState*)state, (const char*)(hulk_uintptr)a, b, "anon_coroutine");
    if (FUN_002139f0((LuaVMState*)state, 1, 1, 0)) {
        FUN_00213190((LuaVMState*)state, -1);
        FUN_00212d80((LuaVMState*)state, 0);
        return 0;
    }
    if (!FUN_00213290((LuaVMState*)state, -1)) {
        FUN_00212d80((LuaVMState*)state, 0);
        return 0;
    }
    FUN_002133d0((LuaVMState*)state, (*(const char**)&DAT_004c5cf8));
    FUN_00213600((LuaVMState*)state, -10000);
    FUN_00212e20((LuaVMState*)state, -2);
    ++counter;
    if (!counter)
        counter = 1;
    U_1d2890 result = counter;
    FUN_00213870((LuaVMState*)state, -2, result);
    FUN_00212d80((LuaVMState*)state, -3);
    return result;
}
