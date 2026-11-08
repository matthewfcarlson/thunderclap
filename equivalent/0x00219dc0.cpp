// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// luaH_getnum: the value under an integer key (the array part, else the hash part), or luaO_nilobject.
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219dc0(LuaVMTable* t, int key) {
    if (1 <= key && key <= t->sizearray)
        return &t->array[key - 1];

    float nk = (float)key;
    union {
        float f;
        unsigned int bits;
    } h;
    h.f = nk + 1.0f;
    unsigned int mod = ((1u << t->lsizenode) - 1) | 1;
    LuaVMNode* n = &t->node[h.bits % mod];
    do {
        if (n->i_key.tt == LUAVM_TNUMBER && n->i_key.value.n == nk)
            return &n->i_val;
        n = n->next;
    } while (n != 0);
    return LUAVM_NILOBJECT;
}
