// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002192c0..0x00219520 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_fdb59fc5 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fdb59fc5 {} using namespace fn_fdb59fc5;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_fdb59fc5 {
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_002192e0(LuaVMState* L, int newsize);
static inline int memcmp_inline(const void* a, const void* b, unsigned int n) {
    const unsigned char* p = (const unsigned char*)a;
    const unsigned char* q = (const unsigned char*)b;
    for (; n != 0; n--, p++, q++)
        if (*p != *q)
            return *p - *q;
    return 0;
}
extern "C" LuaVMString* __cdecl FUN_00219390(LuaVMState* L, const char* str, unsigned int l, unsigned int h);


// 0x002192c0 FUN_002192c0 (29 B): matches/0x002192c0.cpp
// sym: _FUN_002192c0
// luaS_freeall: free the string table's hash array.
extern "C" void __cdecl FUN_002192c0(LuaVMState* L) {
    FUN_0021add0(L, L->l_G->strt.hash, L->l_G->strt.size * (unsigned int)sizeof(LuaVMString*), 0);
}


// 0x002192e0 FUN_002192e0 (173 B): matches/0x002192e0.cpp
// sym: _FUN_002192e0
// luaS_resize: rehash the string table into newsize buckets (not while the collector sweeps the strings).
extern "C" void __cdecl FUN_002192e0(LuaVMState* L, int newsize) {
    if (L->l_G->sweepstrgc > 0)
        return;
    LuaVMString** newhash =
        (LuaVMString**)FUN_0021add0(L, 0, 0, (unsigned int)newsize * (unsigned int)sizeof(LuaVMString*));
    LuaVMStringTable* tb = &L->l_G->strt;
    for (int i = 0; i < newsize; ++i)
        newhash[i] = 0;
    for (int i = 0; i < tb->size; ++i) {
        LuaVMString* p = tb->hash[i];
        while (p) {
            unsigned int h = p->hash & ((unsigned int)newsize - 1);
            LuaVMString* next = (LuaVMString*)p->next;
            p->next = (LuaVMGCObject*)newhash[h];
            newhash[h] = p;
            p = next;
        }
    }
    FUN_0021add0(L, tb->hash, (unsigned int)tb->size * (unsigned int)sizeof(LuaVMString*), 0);
    tb->hash = newhash;
    tb->size = newsize;
}


// 0x00219390 FUN_00219390 (154 B): equivalent/0x00219390.cpp
// sym: _FUN_00219390
// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 4/4)
// newlstr: a new string of l bytes with hash h, linked into the string table (which doubles when over full).
// equiv-conv: FUN_00219390 stack stack stack eax
extern "C" LuaVMString* __cdecl FUN_00219390(LuaVMState* L, const char* str, unsigned int l, unsigned int h) {
    LuaVMString* ts = (LuaVMString*)FUN_0021add0(L, 0, 0, l + (unsigned int)sizeof(LuaVMString) + 1);
    ts->len = l;
    ts->hash = h;
    ts->marked = (unsigned char)L->l_G->currentwhite;
    ts->tt = LUAVM_TSTRING;
    ts->reserved = 0;
    // the original copies with an inline rep movs; a plain forward loop keeps clang from emitting a memcpy call
    {
        char* dst = LUAVM_GETSTR(ts);
        const char* src = str;
        unsigned int w = l >> 2;  // rep movsd, then rep movsb
        while (w--) {
            *(unsigned int*)dst = *(const unsigned int*)src;
            dst += 4;
            src += 4;
        }
        for (unsigned int k = l & 3; k; k--)
            *dst++ = *src++;
    }
    LUAVM_GETSTR(ts)[l] = 0;
    LuaVMStringTable* tb = &L->l_G->strt;
    h &= tb->size - 1;
    ts->next = (LuaVMGCObject*)tb->hash[h];
    tb->hash[h] = ts;
    tb->nuse++;
    if (tb->nuse > (unsigned int)tb->size && tb->size <= 0x3ffffffe)
        FUN_002192e0(L, tb->size * 2);
    return ts;
}


// 0x00219430 FUN_00219430 (160 B): equivalent/0x00219430.cpp
// sym: _FUN_00219430
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 14/14)
// luaS_newlstr: the interned string of l bytes (a dead one found is revived), else a new one.
// MSVC 7.1 expands memcmp inline (repe cmpsb); so does this.
// equiv-conv: FUN_00219390 stack stack stack eax
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


// 0x002194d0 FUN_002194d0 (71 B): matches/0x002194d0.cpp
// sym: _FUN_002194d0
// luaS_newudata: a userdata of s bytes, linked after the global state's dummy udata.
extern "C" LuaVMUdata* __cdecl FUN_002194d0(LuaVMState* L, unsigned int s) {
    LuaVMUdata* u = (LuaVMUdata*)FUN_0021add0(L, 0, 0, s + (unsigned int)sizeof(LuaVMUdata));
    u->marked = (unsigned char)L->l_G->currentwhite;
    u->len = s;
    u->tt = LUAVM_TUSERDATA;
    u->metatable = 0;
    u->next = L->l_G->firstudata->next;
    L->l_G->firstudata->next = (LuaVMGCObject*)u;
    return u;
}

} // namespace fn_fdb59fc5
