// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 12/12)
// inclinenumber: skip a newline sequence ("\n", "\r", "\n\r" or "\r\n") and count the line.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);                                    // luaZ_fill
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token); // luaX_lexerror

// equiv-conv: FUN_0021b0d0 esi
extern "C" void FUN_0021b0d0(LuaVMLexState* ls) {
    int old = ls->current;

    ls->current = (ls->z->n-- > 0) ? (unsigned char)*ls->z->p++ : FUN_0021a550(ls->z);
    if ((ls->current == '\n' || ls->current == '\r') && ls->current != old) {
        ls->current = (ls->z->n-- > 0) ? (unsigned char)*ls->z->p++ : FUN_0021a550(ls->z);
    }
    if (++ls->linenumber >= 0x7ffffffd) {
        FUN_0021afd0(ls, "chunk has too many lines", ls->t.token);
    }
}
