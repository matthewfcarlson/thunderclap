// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 8/8)
// setnodevector: a table's hash part of 2^lsize empty nodes (the global dummy node for 0).
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);

// equiv-conv: FUN_00219c30 ebx esi stack
extern "C" void __cdecl FUN_00219c30(LuaVMState* L, LuaVMTable* t, int lsize) {
    int size = 1 << lsize;

    if (lsize > 24)
        FUN_00214a90(L, "table overflow");

    if (lsize == 0) {
        t->node = L->l_G->dummynode;
    } else {
        t->node = (LuaVMNode*)FUN_0021add0(L, 0, 0, size * (unsigned int)sizeof(LuaVMNode));
        for (int i = 0; i < size; i++) {
            t->node[i].next = 0;
            t->node[i].i_key.tt = LUAVM_TNIL;
            t->node[i].i_val.tt = LUAVM_TNIL;
        }
    }
    t->lsizenode = (unsigned char)lsize;
    t->firstfree = &t->node[size - 1];
}
