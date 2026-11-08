// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 4/4)
// funcinfo: fill ar's source, linedefined, what and short_src from the function func.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00216340(char* out, const char* source, int bufflen);

// equiv-conv: FUN_00214160 ecx eax
extern "C" void FUN_00214160(LuaVMDebug* ar, const LuaVMTObject* func) {
    LuaVMClosure* cl = (LuaVMClosure*)func->value.gc;
    if (cl->c.isC) {
        ar->source = "=[C]";
        ar->linedefined = -1;
        ar->what = "C";
        FUN_00216340(ar->short_src, ar->source, 0x3c);
        return;
    }
    ar->source = LUAVM_GETSTR(cl->l.p->source);
    int line = cl->l.p->lineDefined;
    ar->linedefined = line;
    ar->what = (line != 0) ? "Lua" : "main";
    FUN_00216340(ar->short_src, ar->source, 0x3c);
}
