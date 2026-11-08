// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00338d90 @ 0x00338d90
// cl-flags: /GS
#include "decls/data/lua.h"
#include "decls/data/game/global.h"

extern "C" int __cdecl FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar);

// Lua 5.0 luaL_where: pushes "source:line: " for the given call level, or "".
extern "C" void __cdecl FUN_00338d90(LuaVMState* L, int level)
{
    struct Frame {
        LuaVMDebug ar;
    } f;

    if (FUN_00213fc0(L, level, &f.ar)) {
        FUN_00214bd0(L, "Sl", &f.ar);
        if (f.ar.currentline > 0) {
            FUN_00213470(L, "%s:%d: ", f.ar.short_src, f.ar.currentline);
            return;
        }
    }
    FUN_00213380(L, ((const char*)&DAT_003f335c), 0);
}
