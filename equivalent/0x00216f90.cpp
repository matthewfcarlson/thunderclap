// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// markroot: start a collection: mark the main thread, its globals and the registry.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);

// equiv-conv: FUN_00216f90 edi
extern "C" void __cdecl FUN_00216f90(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    g->grayagain = 0;
    g->weak = 0;
    LuaVMGCObject* o = (LuaVMGCObject*)g->mainthread;
    if (o->marked & 3)
        FUN_002164b0(g, o);
    LuaVMState* th = g->mainthread;
    if (th->_gt.tt >= LUAVM_TSTRING) {
        o = th->_gt.value.gc;
        if (o->marked & 3)
            FUN_002164b0(g, o);
    }
    LuaVMGlobal* g2 = L->l_G;
    if (g2->l_registry.tt >= LUAVM_TSTRING) {
        o = g2->l_registry.value.gc;
        if (o->marked & 3)
            FUN_002164b0(g, o);
    }
    g->gcstate = 0;
}
