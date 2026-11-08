// luaC_barrierf: a black object o now points at the white v: mark v while propagating, else make o not black.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002164b0(LuaVMGlobal* g, LuaVMGCObject* o);

extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v) {
    LuaVMGlobal* g = L->l_G;
    if (g->gcstate != 0) {
        o->marked &= 0xfb;
        return;
    }
    FUN_002164b0(g, v);
}
