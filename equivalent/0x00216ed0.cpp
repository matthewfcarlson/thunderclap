// STATUS: equivalent (tools/equiv.py level 3: 2951 inputs, branch coverage 6/6)
// GCTM: take the next userdata awaiting finalization, put it back after the dummy udata (white) and call its __gc.
#include "decls/data/lua.h"

extern "C" const LuaVMTObject* __cdecl FUN_00217580(LuaVMTable* events, int event, LuaVMString* ename);
extern "C" void __cdecl FUN_002159e0(LuaVMState* L, LuaVMTObject* func, int nresults);

// equiv-conv: FUN_00216ed0 esi
extern "C" void __cdecl FUN_00216ed0(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    LuaVMGCObject* first = g->firstudata;
    LuaVMUdata* u = (LuaVMUdata*)g->tmudata;

    g->tmudata = u->next;
    u->next = first->next;
    L->l_G->firstudata->next = (LuaVMGCObject*)u;
    u->marked = (u->marked & 0xf8) | (unsigned char)g->currentwhite;

    LuaVMTable* mt = u->metatable;
    if (mt != 0 && (mt->flags & 4) == 0) {
        const LuaVMTObject* tm = FUN_00217580(mt, 2, L->l_G->tmname[2]);
        if (tm != 0) {
            unsigned char oldallow = L->allowhook;
            L->allowhook = 0;
            LUAVM_SETOBJ(L->top, tm);
            L->top[1].value.gc = (LuaVMGCObject*)u;
            L->top[1].tt = LUAVM_TUSERDATA;
            L->top += 2;
            FUN_002159e0(L, L->top - 2, 0);
            L->allowhook = oldallow;
        }
    }
}
