// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 14/14)
// luaS_newlstr: the interned string of l bytes (a dead one found is revived), else a new one.
#include "decls/data/lua.h"

// MSVC 7.1 expands memcmp inline (repe cmpsb); so does this.
static inline int memcmp_inline(const void* a, const void* b, unsigned int n) {
    const unsigned char* p = (const unsigned char*)a;
    const unsigned char* q = (const unsigned char*)b;
    for (; n != 0; n--, p++, q++)
        if (*p != *q)
            return *p - *q;
    return 0;
}

// equiv-conv: FUN_00219390 stack stack stack eax
extern "C" LuaVMString* __cdecl FUN_00219390(LuaVMState* L, const char* str, unsigned int l, unsigned int h);

extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l) {
    unsigned int h = l;
    unsigned int step = (l >> 5) + 1;
    for (unsigned int l1 = l; l1 >= step; l1 -= step)
        h = h ^ ((h << 5) + (h >> 2) + (unsigned char)str[l1 - 1]);

    LuaVMGlobal* g = L->l_G;
    for (LuaVMString* ts = g->strt.hash[h & (g->strt.size - 1)]; ts != 0; ts = (LuaVMString*)ts->next) {
        if (ts->len == l && memcmp_inline(str, LUAVM_GETSTR(ts), l) == 0) {
            LuaVMGlobal* g2 = L->l_G;
            if (ts->marked & (g2->currentwhite ^ 3))
                ts->marked ^= 3;
            return ts;
        }
    }
    return FUN_00219390(L, str, l, h);
}
