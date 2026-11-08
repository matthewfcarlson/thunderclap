// STATUS: equivalent (tools/equiv.py level 3: 2615 inputs, branch coverage 32/32)
// FUN_0033aa40 @ 0x0033aa40
// cl-flags: /GS
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" LuaVMState* __cdecl FUN_00213290(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00212fb0(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" const char* __cdecl FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00213c90(LuaVMState* L, int n);
extern "C" int __cdecl FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar);
extern "C" int __cdecl FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar);

struct Frame_33aa40 {
    int arg;
    int firstpart;
    LuaVMDebug ar;
};

// Lua 5.0 errorfb (stack traceback builder)
extern "C" int __cdecl FUN_0033aa40(LuaVMState* L)
{
    Frame_33aa40 f;
    int level = 1;
    LuaVMState* L1;

    f.firstpart = 1;
    if (FUN_00212f00(L, 1) == 8) {
        f.arg = 1;
        L1 = FUN_00213290(L, 1);
    } else {
        f.arg = 0;
        L1 = L;
    }

    if (FUN_00212d70(L) == f.arg) {
        FUN_00213380(L, "", 0);
    } else {
        if (!FUN_00212fb0(L, f.arg + 1)) {
            return 1;
        }
        FUN_00213380(L, "\n", 1);
    }
    FUN_00213380(L, "stack traceback:", 16);

    while (FUN_00213fc0(L1, level++, &f.ar)) {
        if (level > 12 && f.firstpart) {
            if (!FUN_00213fc0(L1, level + 10, &f.ar)) {
                level--;
            } else {
                FUN_00213380(L, "\n\t...", 5);
                while (FUN_00213fc0(L1, level + 10, &f.ar))
                    level++;
            }
            f.firstpart = 0;
            continue;
        }
        FUN_00213380(L, "\n\t", 2);
        FUN_00214bd0(L1, "Snl", &f.ar);
        FUN_00213470(L, "%s:", f.ar.short_src);
        if (f.ar.currentline > 0)
            FUN_00213470(L, "%d:", f.ar.currentline);
        switch (*f.ar.namewhat) {
        case 'f':
        case 'g':
        case 'l':
        case 'm':
            FUN_00213470(L, " in function `%s'", f.ar.name);
            break;
        default:
            if (*f.ar.what == 'm')
                FUN_00213470(L, " in main chunk");
            else if (*f.ar.what == 'C' || *f.ar.what == 't')
                FUN_00213380(L, " ?", 2);
            else
                FUN_00213470(L, " in function <%s:%d>", f.ar.short_src, f.ar.linedefined);
            break;
        }
        FUN_00213c90(L, FUN_00212d70(L) - f.arg);
    }
    FUN_00213c90(L, FUN_00212d70(L) - f.arg);
    return 1;
}
