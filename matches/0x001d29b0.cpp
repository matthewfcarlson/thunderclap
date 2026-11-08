// FUN_001d29b0 @ 0x001d29b0
#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#include "gen/owners.h"

extern "C" {
void __cdecl FUN_002133d0(LuaVMState* h, const char* v);
void __cdecl FUN_00213600(LuaVMState* h, int v);
void __cdecl FUN_00213640(LuaVMState* h, int idx, int v);
LuaVMState* __cdecl FUN_00213290(LuaVMState* h, int idx);
void __cdecl FUN_00212d80(LuaVMState* h, int v);
int __cdecl FUN_00215d10(LuaVMState* a, int b);
void __cdecl FUN_00213320(LuaVMState* h);
void __cdecl FUN_00213870(LuaVMState* h, int idx, int v);
}

// handle (include/gen/owners.h Runner_1d29b0 +0x08) is the lua_State, an int member there, and the gen
// declaration of FUN_001d17f0 takes it as an int: cast at the use.
char owners::Runner_1d29b0::FUN_001d29b0(hulk_intptr arg, char *failed)
{
    if (((int)arg) == 0) {
        *failed = 1;
        return 0;
    }
    FUN_002133d0((LuaVMState*)(hulk_intptr)handle, DAT_004c5cf8);
    FUN_00213600((LuaVMState*)(hulk_intptr)handle, -10000);
    FUN_00213640((LuaVMState*)(hulk_intptr)handle, -1, ((int)arg));
    LuaVMState* r = FUN_00213290((LuaVMState*)(hulk_intptr)handle, -1);
    if (r == 0) {
        FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -3);
        *failed = 1;
        return 0;
    }
    if (FUN_001d17f0(handle) != 2) {
        FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -3);
        *failed = 1;
        return 0;
    }
    FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -3);
    if (FUN_00215d10(r, 0) != 0) {
        *failed = 1;
        FUN_00212d80((LuaVMState*)(hulk_intptr)handle, 0);
        return 0;
    }
    FUN_002133d0((LuaVMState*)(hulk_intptr)handle, DAT_004c5cf8);
    FUN_00213600((LuaVMState*)(hulk_intptr)handle, -10000);
    FUN_00213640((LuaVMState*)(hulk_intptr)handle, -1, ((int)arg));
    if (FUN_001d17f0(handle) == 3) {
        FUN_002133d0((LuaVMState*)(hulk_intptr)handle, DAT_004c5cf8);
        FUN_00213600((LuaVMState*)(hulk_intptr)handle, -10000);
        FUN_00213320((LuaVMState*)(hulk_intptr)handle);
        FUN_00213870((LuaVMState*)(hulk_intptr)handle, -2, ((int)arg));
        FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -4);
        return 0;
    }
    FUN_00212d80((LuaVMState*)(hulk_intptr)handle, -3);
    return 1;
}
