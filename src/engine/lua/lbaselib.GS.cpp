// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0033d6e0..0x0033eb70 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f9aa3fa4 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9aa3fa4 {} using namespace fn_f9aa3fa4;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f9aa3fa4 {
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00339fe0(LuaVMState* L, int narg, int def);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" int __cdecl FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
} // namespace fn_f9aa3fa4
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char* buf, const char* fmt, ...);
#endif
namespace fn_f9aa3fa4 {
extern "C" void __cdecl FUN_00339dc0(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00339070(LuaVMState* L, int obj, const char* event);
extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_002133d0(LuaVMState* L, const char* s);
extern "C" int __cdecl FUN_00213160(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" const void* __cdecl FUN_002132b0(LuaVMState* L, int idx);
extern "C" void* __cdecl FUN_00213260(LuaVMState* L, int idx);
extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" int __cdecl FUN_00212d70(LuaVMState* L);


// 0x0033d9e0 FUN_0033d9e0 (183 B): equivalent/0x0033d9e0.cpp
// sym: ?FUN_0033d9e0@fn_f9aa3fa4@@YAXPAULuaVMState@@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033d9e0 @ 0x0033d9e0
// lbaselib getfunc: push the function of argument 1 (a function or a stack level)
// equiv-conv: FUN_0033d9e0 esi
void __cdecl FUN_0033d9e0(LuaVMState* L) {
    LuaVMDebug ar;
    if (FUN_00212f00(L, 1) == LUAVM_TFUNCTION) {
        FUN_00212ed0(L, 1);
    } else {
        int level = FUN_00339fe0(L, 1, 1);
        if (level < 0)
            FUN_00339c30(L, 1, "level must be non-negative");
        if (!FUN_00213fc0(L, level, &ar))
            FUN_00339c30(L, 1, "invalid level");
        FUN_00214bd0(L, "f", &ar);
        if (!FUN_00212f00(L, -1))
            FUN_00338e20(L, "no function environment for tail call at level %d", level);
    }
}


// 0x0033e250 FUN_0033e250 (369 B): equivalent/0x0033e250.cpp
// sym: _FUN_0033e250
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 15/15)
// FUN_0033e250 @ 0x0033e250
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


// 0x0033ea00 FUN_0033ea00 (142 B): matches/0x0033ea00.cpp
// sym: _FUN_0033ea00
// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033ea00 @ 0x0033ea00
// Lua coroutine.status
extern "C" int __cdecl FUN_0033ea00(LuaVMState* L) {
    LuaVMDebug ar;
    LuaVMState* co = FUN_00213290(L, 1);
    if (co == 0)
        FUN_00339c30(L, 1, "coroutine expected");
    if (L == co) {
        FUN_00213380(L, "running", 7);
    } else if (FUN_00213fc0(co, 0, &ar) == 0 && FUN_00212d70(co) == 0) {
        FUN_00213380(L, "dead", 4);
    } else {
        FUN_00213380(L, "suspended", 9);
    }
    return 1;
}

} // namespace fn_f9aa3fa4
