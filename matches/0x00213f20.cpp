// currentline: the source line ci's Lua function is at (-1 for a C function or before the first instruction).
#include "decls/data/lua.h"

extern "C" int __fastcall FUN_00213f20(LuaVMState* L, LuaVMCallInfo* ci) {
    LuaVMClosure* cl;
    LuaVMProto* p;
    int pc;
    if (ci->base[-1].tt != LUAVM_TFUNCTION)
        return -1;
    cl = (LuaVMClosure*)ci->base[-1].value.gc;
    if (cl->c.isC != 0)
        return -1;
    p = cl->l.p;
    pc = (int)(ci->savedpc - p->code);
    --pc;
    if (pc < 0)
        return -1;
    int* lineinfo = p->lineinfo;
    return lineinfo ? lineinfo[pc] : 0;
}
