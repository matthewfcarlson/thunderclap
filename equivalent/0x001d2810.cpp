// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 10/10)
// FUN_001d2810 @ 0x001d2810
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212d70(LuaVMState *L);
extern "C" int __cdecl FUN_00339a60(LuaVMState *L, const char *buf, unsigned int len, const char *name);
extern "C" int __cdecl FUN_002139f0(LuaVMState *L, int nargs, int nresults, int errfunc);
extern "C" void __cdecl FUN_00212d80(LuaVMState *L, int top);

class ScriptHandler {
public:
    char pad0[8];
    LuaVMState *main;
    int FUN_001d2810(LuaVMState *L, const char *buf, int len, const char *name);
};

int ScriptHandler::FUN_001d2810(LuaVMState *L, const char *buf, int len, const char *name)
{
    int top = FUN_00212d70(main);
    if (len == -1) {
        const char *e = buf;
        while (*e != 0)
            e++;
        len = (int)(e - buf);
    }
    if (name == 0)
        name = "=ScriptHandler::DoLuaBuffer";
    int r = FUN_00339a60(L, buf, len, name);
    if (r != 0 || (r = FUN_002139f0(L, 0, -1, 0)) != 0)
        FUN_00212d80(L, top);
    return r;
}
