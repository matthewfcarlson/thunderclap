// luaC_link: put a new object on the root list, white.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt) {
    LuaVMGlobal* g = L->l_G;
    o->next = g->rootgc;
    g->rootgc = o;
    o->marked = (unsigned char)g->currentwhite;
    o->tt = tt;
}
