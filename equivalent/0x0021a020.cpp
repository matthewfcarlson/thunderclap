// STATUS: equivalent (tools/equiv.py level 3: 1449 inputs, branch coverage 12/12)
// luaH_next: the key and value after key (in key[0], key[1]); 0 at the end.
#include "decls/data/lua.h"

// equiv-conv: FUN_00219fb0 eax edi stack
extern "C" int __cdecl FUN_00219fb0(const LuaVMTObject* key, LuaVMTable* t, LuaVMState* L);

extern "C" int __cdecl FUN_0021a020(LuaVMState* L, LuaVMTable* t, LuaVMTObject* key) {
    int i = FUN_00219fb0(key, t, L) + 1;
    int sizearray = t->sizearray;
    if (i < sizearray) {
        LuaVMTObject* slot = t->array + i;
        while (i < sizearray) {
            if (slot->tt != LUAVM_TNIL) {
                key[0].tt = LUAVM_TNUMBER;
                key[0].value.n = (float)(i + 1);
                LUAVM_SETOBJ(key + 1, &t->array[i]);
                return 1;
            }
            ++i;
            ++slot;
        }
    }
    i -= sizearray;
    int sizenode = (int)(1u << (t->lsizenode & 31));
    if (i < sizenode) {
        LuaVMNode* n = t->node + i;
        while (i < sizenode) {
            if (n->i_val.tt != LUAVM_TNIL) {
                LUAVM_SETOBJ(key, &n->i_key);
                LUAVM_SETOBJ(key + 1, &t->node[i].i_val);
                return 1;
            }
            ++i;
            ++n;
        }
    }
    return 0;
}
