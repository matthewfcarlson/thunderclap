// STATUS: equivalent (tools/equiv.py level 3: 2989 inputs, branch coverage 8/8)
// sweepstrings: sweep the string table's buckets from g->sweepstrgc until lim bytes are done; the budget left.
#include "decls/data/lua.h"

extern "C" LuaVMGCObject** __cdecl FUN_002171c0(LuaVMState* L, LuaVMGCObject** p, int all, int* lim, int* count);

// equiv-conv: FUN_00216e10 stack stack ebx
extern "C" int __cdecl FUN_00216e10(int all, int lim, LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    int i = g->sweepstrgc;
    while (i < g->strt.size) {
        LuaVMGCObject** p = (LuaVMGCObject**)&L->l_G->strt.hash[i];
        int dead = 0x7fffffff;
        if (*p != 0)
            FUN_002171c0(L, p, all, &dead, (int*)&g->strt.nuse);
        lim += dead - 0x7fffffff;
        if (lim <= 0)
            break;
        ++i;
    }
    g->sweepstrgc = i + 1;
    return lim;
}
