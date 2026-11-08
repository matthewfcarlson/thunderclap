// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 15/15)
// FUN_0033e250 @ 0x0033e250
// cl-flags: /GS
extern "C" int sprintf(char* buf, const char* fmt, ...);

// luaB_tostring
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00339070(LuaVMState* L, int obj, const char* event);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213160(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" const void* __cdecl FUN_002132b0(LuaVMState* L, int idx);
extern "C" void* __cdecl FUN_00213260(LuaVMState* L, int idx);
extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);

extern "C" int __cdecl FUN_0033e250(LuaVMState* L)
{
    char buff[20];
    const char* name = "";
    const void* ptr = 0;

    FUN_00339dc0(L, 1);
    if (FUN_00339070(L, 1, "__tostring") != 0) {
        return 1;
    }
    switch (FUN_00212f00(L, 1)) {
    case 3:
        FUN_002133d0(L, FUN_00213190(L, 1));
        return 1;
    case 4:
        FUN_00212ed0(L, 1);
        return 1;
    case 1:
        FUN_002133d0(L, FUN_00213160(L, 1) != 0 ? "true" : "false");
        return 1;
    case 0:
        FUN_00213380(L, "nil", 3);
        return 1;
    case 5:
        ptr = FUN_002132b0(L, 1);
        name = "table";
        break;
    case 6:
        ptr = FUN_002132b0(L, 1);
        name = "function";
        break;
    case 2:
    case 7:
        ptr = FUN_00213260(L, 1);
        name = "userdata";
        break;
    case 8:
        ptr = FUN_00213290(L, 1);
        name = "thread";
        break;
    default:
        break;
    }
    sprintf(buff, "%p", ptr);
    FUN_00213470(L, "%s: %s", name, buff);
    return 1;
}
