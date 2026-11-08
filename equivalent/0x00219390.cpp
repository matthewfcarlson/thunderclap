// STATUS: equivalent (tools/equiv.py level 3: 134 inputs, branch coverage 4/4)
// newlstr: a new string of l bytes with hash h, linked into the string table (which doubles when over full).
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_002192e0(LuaVMState* L, int newsize);

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
