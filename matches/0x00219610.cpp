// luaF_findupval: the open upvalue for stack slot level (the list is ordered by level, highest first), made if absent.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

extern "C" LuaVMUpVal* __cdecl FUN_00219610(LuaVMState* L, LuaVMTObject* level) {
    LuaVMUpVal* p = (LuaVMUpVal*)L->openupval;
    LuaVMGCObject** pp = &L->openupval;
    while (p != 0 && p->v >= level) {
        if (p->v == level)
            return p;
        pp = &p->next;
        p = (LuaVMUpVal*)p->next;
    }
    LuaVMUpVal* v = (LuaVMUpVal*)FUN_0021add0(L, 0, 0, sizeof(LuaVMUpVal));
    v->tt = LUAVM_TUPVAL;
    v->marked = (unsigned char)L->l_G->currentwhite;
    v->v = level;
    v->next = *pp;
    *pp = (LuaVMGCObject*)v;
    return v;
}
