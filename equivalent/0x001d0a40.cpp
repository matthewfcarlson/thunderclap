// STATUS: equivalent (tools/equiv.py level 3: 2606 inputs, branch coverage 30/30)
// FUN_001d0a40 @ 0x001d0a40
// cl-flags: /GS
#include "decls/data/lua.h"


extern "C" int FUN_00212d70(LuaVMState* L);
extern "C" int FUN_00212fb0(LuaVMState* L, int idx);
extern "C" void FUN_00212e20(LuaVMState* L, int idx);
extern "C" void FUN_00213380(LuaVMState* L, const char* s, unsigned int len);
extern "C" const char* FUN_00213470(LuaVMState* L, const char* fmt, ...);
extern "C" void FUN_00213c90(LuaVMState* L, int n);
extern "C" int FUN_00213fc0(LuaVMState* L, int level, LuaVMDebug* ar);
extern "C" int FUN_00214bd0(LuaVMState* L, const char* what, LuaVMDebug* ar);

// Lua error handler: pushes the "LUA SCRIPT ERROR" banner and a stack traceback.
extern "C" int FUN_001d0a40(LuaVMState* L)
{
    LuaVMDebug ar;
    int level = 1;
    int firstpart = 1;
    int proceed = 1;

    if (FUN_00212d70(L) == 0) {
        FUN_00213380(L, "", 0);
    } else if (FUN_00212fb0(L, 1) == 0) {
        proceed = 0;
    } else {
        FUN_00213380(L, "\n", 1);
    }

    if (proceed) {
        FUN_00213380(L, "\n***** LUA SCRIPT ERROR *****\n", 0x1e);
        FUN_00212e20(L, 1);
        FUN_00213380(L, "stack traceback:", 0x10);
        while (FUN_00213fc0(L, level, &ar)) {
            level++;
            if (level > 12 && firstpart) {
                if (!FUN_00213fc0(L, level + 10, &ar)) {
                    level--;
                } else {
                    FUN_00213380(L, "\n\t...", 5);
                    while (FUN_00213fc0(L, level + 10, &ar))
                        level++;
                }
                firstpart = 0;
                continue;
            }
            FUN_00213380(L, "\n\t", 2);
            FUN_00214bd0(L, "Snl", &ar);
            FUN_00213470(L, "%s:", ar.source);
            if (ar.currentline > 0)
                FUN_00213470(L, "%d:", ar.currentline);
            switch (*ar.namewhat) {
            case 'f':
            case 'g':
            case 'l':
            case 'm':
                FUN_00213470(L, " in function `%s'", ar.name);
                break;
            default:
                if (*ar.what == 'm') {
                    FUN_00213470(L, " in main chunk");
                } else if (*ar.what == 'C' || *ar.what == 't') {
                    FUN_00213380(L, " ?", 2);
                } else {
                    FUN_00213470(L, " in function <%s:%d>", ar.short_src, ar.linedefined);
                }
                break;
            }
            FUN_00213c90(L, FUN_00212d70(L));
        }
        FUN_00213c90(L, FUN_00212d70(L));
    }
    return 1;
}
