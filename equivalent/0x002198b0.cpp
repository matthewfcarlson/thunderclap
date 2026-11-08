// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 6/6)
// luaH_mainposition: the node a key hashes to (numbers, booleans, strings by their hash, pointers by address).
#include "decls/data/lua.h"

// equiv-conv: FUN_00219870 esi stack
extern "C" LuaVMNode* __cdecl FUN_00219870(const LuaVMTable* t, float n);

extern "C" LuaVMNode* __cdecl FUN_002198b0(const LuaVMTable* t, const LuaVMTObject* key) {
    if (key->tt == LUAVM_TNUMBER)
        return FUN_00219870(t, key->value.n);
    unsigned int mask = (1U << (t->lsizenode & 31)) - 1U;
    unsigned int index;
    switch (key->tt) {
    case LUAVM_TBOOLEAN:
        index = (unsigned int)key->value.b & mask;
        break;
    case LUAVM_TSTRING:
        index = ((const LuaVMString*)key->value.gc)->hash & mask;
        break;
    default:  // the original hashes the 32-bit address
        index = (unsigned int)(hulk_uintptr)key->value.p % (mask | 1U);
        break;
    }
    return t->node + index;
}
