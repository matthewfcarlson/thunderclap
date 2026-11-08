// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 16/16)
// traceexec: save the pc and call the count hook or (on a new line or a jump back) the line hook.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00215520(LuaVMState* L, int event, int line);

// equiv-conv: FUN_002176c0 ebx edi
extern "C" void __cdecl FUN_002176c0(LuaVMState* L, const LuaVMInstruction* pc) {
    unsigned char mask = L->hookmask;
    LuaVMCallInfo* ci = L->ci;
    const LuaVMInstruction* oldpc = ci->savedpc;
    ci->savedpc = pc;

    if (mask > 4 && L->hookcount == 0) {
        L->hookcount = L->basehookcount;
        FUN_00215520(L, 3, -1);
        return;
    }

    if (mask & 4) {
        LuaVMProto* p = ((LuaVMLClosure*)ci->base[-1].value.gc)->p;
        int npc = (int)(pc - p->code) - 1;
        int newline = p->lineinfo ? p->lineinfo[npc] : 0;
        if (npc == 0 || pc <= oldpc || newline != (p->lineinfo ? p->lineinfo[(int)(oldpc - p->code) - 1] : 0))
            FUN_00215520(L, 2, newline);
    }
}
