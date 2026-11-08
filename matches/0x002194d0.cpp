// luaS_newudata: a userdata of s bytes, linked after the global state's dummy udata.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" LuaVMUdata* __cdecl FUN_002194d0(LuaVMState* L, unsigned int s) {
    LuaVMUdata* u = (LuaVMUdata*)FUN_0021add0(L, 0, 0, s + (unsigned int)sizeof(LuaVMUdata));
    u->marked = (unsigned char)L->l_G->currentwhite;
    u->len = s;
    u->tt = LUAVM_TUSERDATA;
    u->metatable = 0;
    u->next = L->l_G->firstudata->next;
    L->l_G->firstudata->next = (LuaVMGCObject*)u;
    return u;
}
