// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 6/6)
// FUN_00339c30 @ 0x00339c30
// cl-flags: /GS
// luaL_argerror
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00339c30(LuaVMState* state, int argument, const char* message) {
    LuaVMDebug info;
    FUN_00213fc0(state, 0, &info);
    FUN_00214bd0(state, "n", &info);
    const char* kind = info.namewhat;
    const char* method = "method";
    int i;
    for (i = 0; i < 7; ++i) {
        if (kind[i] != method[i]) break;
    }
    int result;
    if (i == 7 && --argument == 0) {
        result = FUN_00338e20(state, "calling `%s' on bad self (%s)", info.name, message);
    } else {
        if (!info.name) info.name = "?";
        result = FUN_00338e20(state, "bad argument #%d to `%s' (%s)", argument, info.name, message);
    }
    return result;
}
