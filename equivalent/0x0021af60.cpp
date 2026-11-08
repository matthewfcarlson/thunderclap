// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 8/8)
// txtToken: a name, string or number token as the buffer's text (NUL-terminated), any other by luaX_token2str.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" const char* __cdecl FUN_0021af00(LuaVMLexState* ls, int token);
// equiv-conv: FUN_0021af60 eax edi
extern "C" const char* FUN_0021af60(int token, LuaVMLexState* ls) {
    if (token != 0x116 && (token <= 0x11c || token > 0x11e))
        return FUN_0021af00(ls, token);
    LuaVMBuffer* b = ls->buff;
    if (b->n + 1 > b->buffsize) {
        unsigned int size = b->buffsize;
        b->buffer = (char*)FUN_0021add0(ls->L, b->buffer, size, size * 2 + 0x20);
        b->buffsize = b->buffsize * 2 + 0x20;
    }
    b->buffer[b->n] = 0;
    ++b->n;
    return ls->buff->buffer;
}
