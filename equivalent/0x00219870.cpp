// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// hashnum: the main position of a number key (the bits of n + 1 modulo the odd node count).
#include "decls/data/lua.h"

// equiv-conv: FUN_00219870 esi stack
extern "C" LuaVMNode* __cdecl FUN_00219870(const LuaVMTable* t, float n) {
    unsigned int mask = (1u << (t->lsizenode & 31)) - 1u;
    mask |= 1u;
    union {
        float f;
        unsigned int u;
    } bits;
    bits.f = n + 1.0f;
    return t->node + bits.u % mask;
}
