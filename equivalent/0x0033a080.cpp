// STATUS: equivalent (tools/equiv.py level 3: 3098 inputs, branch coverage 23/24, incomplete)
// FUN_0033a080 @ 0x0033a080
// cl-flags: /GS
// db_getinfo
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212f00(LuaVMState *L, int idx);
extern "C" LuaVMState *__cdecl FUN_00213290(LuaVMState *L, int idx);
extern "C" const char *__cdecl FUN_00339e60(LuaVMState *L, int narg, const char *def, unsigned int *len);
extern "C" int __cdecl FUN_00212f70(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_00213120(LuaVMState *L, int idx);
extern "C" int __cdecl FUN_00213fc0(LuaVMState *L, int level, LuaVMDebug *ar);
extern "C" void __cdecl FUN_00213320(LuaVMState *L);
extern "C" const char *__cdecl FUN_00213470(LuaVMState *L, const char *fmt, ...);
extern "C" const char *__cdecl FUN_00213190(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00212ed0(LuaVMState *L, int idx);
extern "C" void __cdecl FUN_00212cb0(LuaVMState *from, LuaVMState *to, int n);
extern "C" int __cdecl FUN_00214bd0(LuaVMState *L, const char *what, LuaVMDebug *ar);
extern "C" int __cdecl FUN_00339c30(LuaVMState *L, int narg, const char *msg);
extern "C" void __cdecl FUN_00213680(LuaVMState *L, int narr, int nrec);
extern "C" void __cdecl FUN_002133d0(LuaVMState *L, const char *s);
extern "C" void __cdecl FUN_00213360(LuaVMState *L, int n);
extern "C" void __cdecl FUN_00213790(LuaVMState *L, int idx, const char *k);

extern "C" int __cdecl FUN_0033a080(LuaVMState *L)
{
    LuaVMDebug ar;
    LuaVMState *L1;
    int arg;
    if (FUN_00212f00(L, 1) == 8) {
        arg = 1;
        L1 = FUN_00213290(L, 1);
    } else {
        arg = 0;
        L1 = L;
    }
    const char *options = FUN_00339e60(L, arg + 2, "flnSu", 0);
    if (FUN_00212f70(L, arg + 1)) {
        if (!FUN_00213fc0(L1, FUN_00213120(L, arg + 1), &ar)) {
            FUN_00213320(L);
            return 1;
        }
    } else if (FUN_00212f00(L, arg + 1) == 6) {
        FUN_00213470(L, ">%s", options);
        options = FUN_00213190(L, -1);
        FUN_00212ed0(L, arg + 1);
        FUN_00212cb0(L, L1, 1);
    } else {
        int r = FUN_00339c30(L, arg + 1, "function or level expected");
        return r;
    }
    if (!FUN_00214bd0(L1, options, &ar)) {
        int r = FUN_00339c30(L, arg + 2, "invalid option");
        return r;
    }
    FUN_00213680(L, 0, 0);
    for (; *options; options++) {
        switch (*options) {
        case 'S':
            FUN_002133d0(L, ar.source);
            FUN_00213790(L, -2, "source");
            FUN_002133d0(L, ar.short_src);
            FUN_00213790(L, -2, "short_src");
            FUN_00213360(L, ar.linedefined);
            FUN_00213790(L, -2, "linedefined");
            FUN_002133d0(L, ar.what);
            FUN_00213790(L, -2, "what");
            break;
        case 'l':
            FUN_00213360(L, ar.currentline);
            FUN_00213790(L, -2, "currentline");
            break;
        case 'u':
            FUN_00213360(L, ar.nups);
            FUN_00213790(L, -2, "nups");
            break;
        case 'n':
            FUN_002133d0(L, ar.name);
            FUN_00213790(L, -2, "name");
            FUN_002133d0(L, ar.namewhat);
            FUN_00213790(L, -2, "namewhat");
            break;
        case 'f':
            if (L == L1)
                FUN_00212ed0(L, -2);
            else
                FUN_00212cb0(L1, L, 1);
            FUN_00213790(L, -2, "func");
            break;
        default:
            break;
        }
    }
    return 1;
}
