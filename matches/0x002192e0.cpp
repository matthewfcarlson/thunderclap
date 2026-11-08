// luaS_resize: rehash the string table into newsize buckets (not while the collector sweeps the strings).
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

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
