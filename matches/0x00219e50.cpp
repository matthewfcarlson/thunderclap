// luaH_getstr: the value under a string key, or luaO_nilobject.
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key) {
    unsigned int size = 1u << t->lsizenode;
    LuaVMNode* n = t->node + ((size - 1) & key->hash);
    while (n->i_key.tt != LUAVM_TSTRING || (LuaVMString*)n->i_key.value.gc != key) {
        n = n->next;
        if (!n)
            return LUAVM_NILOBJECT;
    }
    return &n->i_val;
}
