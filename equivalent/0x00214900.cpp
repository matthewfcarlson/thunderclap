// STATUS: equivalent (tools/equiv.py level 3: 3091 inputs, branch coverage 12/16, incomplete)
// cl-flags: /GS
// addinfo: prefix "chunk:line: " to msg (pushed) when the running function is a Lua function.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00216340(char* out, const char* source, int bufflen);
extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);

// equiv-conv: FUN_00214900 ebx stack
extern "C" void FUN_00214900(LuaVMState* L, const char* msg)
{
    struct Frame {
        char buff[60];
    } fr;
    LuaVMCallInfo* ci = L->ci;
    LuaVMTObject* func = ci->base - 1;
    if (func->tt == LUAVM_TFUNCTION && ((LuaVMClosure*)func->value.gc)->c.isC == 0) {
        LuaVMProto* p = ((LuaVMClosure*)func->value.gc)->l.p;
        int pc = (int)(ci->savedpc - p->code) - 1;
        int line;
        if (pc < 0)
            line = -1;
        else if (p->lineinfo != 0)
            line = p->lineinfo[pc];
        else
            line = 0;
        FUN_00216340(fr.buff, LUAVM_GETSTR(p->source), 60);
        FUN_00216320(L, "%s:%d: %s", fr.buff, line, msg);
    }
}
