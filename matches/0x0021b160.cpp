// luaX_setinput: start the lexer on a stream (line 1, no lookahead, no function) and read the first character.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" void __cdecl FUN_0021b160(LuaVMState* L, LuaVMLexState* ls, LuaVMZio* z, LuaVMString* source) {
    ls->L = L;
    ls->z = z;
    ls->linenumber = 1;
    ls->lastline = 1;
    ls->lookahead.token = 0x11f;  // TK_EOS
    ls->fs = 0;
    ls->source = source;
    unsigned int n = z->n;
    z->n = n - 1;
    LuaVMZio* q = ls->z;
    if (n > 0) {
        const char* t = q->p;
        int v = (unsigned char)*t++;
        q->p = t;
        ls->current = v;
        return;
    }
    ls->current = FUN_0021a550(q);
}
