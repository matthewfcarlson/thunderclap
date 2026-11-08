// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 18/18)
// sweeplist: free the dead objects of the list at p (re-whiten the live ones, sweep threads' open upvalues) until
// *lim bytes are done; the link reached.
#include "decls/data/lua.h"

// equiv-conv: FUN_00216d30 ecx eax
extern "C" void __cdecl FUN_00216d30(LuaVMState* L, LuaVMGCObject* o);

extern "C" LuaVMGCObject** __cdecl FUN_002171c0(LuaVMState* L, LuaVMGCObject** p, int all, int* lim, int* count) {
    LuaVMGlobal* g = L->l_G;
    unsigned int dead = g->currentwhite ^ 3;
    int l = *lim;
    if (all)
        dead |= 0x20;
    LuaVMGCObject* curr = *p;
    if (curr) {
        do {
            if ((((unsigned int)curr->marked ^ 0x20) & dead) != dead) {
                curr->marked = (unsigned char)((curr->marked & 0xf8) | (unsigned char)g->currentwhite);
                if (curr->tt == LUAVM_TTHREAD) {
                    int nested = 0x7fffffff;
                    if (((LuaVMState*)curr)->openupval)
                        FUN_002171c0(L, &((LuaVMState*)curr)->openupval, all, &nested, count);
                    l += nested - 0x7fffffff;
                }
                p = &curr->next;
                l -= 8;
            } else {
                *p = curr->next;
                if (curr == g->rootgc)
                    g->rootgc = curr->next;
                FUN_00216d30(L, curr);
                l -= 4;
                if (count)
                    --*count;
            }
            if (l <= 0)
                break;
            curr = *p;
        } while (curr);
    }
    *lim = l;
    return p;
}
