// STATUS: equivalent (tools/equiv.py level 3: 3061 inputs, branch coverage 10/10)
// skip_sep: count the run of '*' after a long bracket's opening character (-count - 1 when the closing one differs).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

// equiv-conv: FUN_0021b1c0 edi
extern "C" void FUN_0021b1c0(LuaVMLexState* ls);

// equiv-conv: FUN_0021b480 eax
extern "C" int FUN_0021b480(LuaVMLexState* ls) {
    int count = 0;
    int s = ls->current;
    FUN_0021b1c0(ls);
    while (ls->current == '*') {
        LuaVMBuffer* b = ls->buff;
        if (b->n + 1 > b->buffsize) {
            b->buffer = (char*)FUN_0021add0(ls->L, b->buffer, b->buffsize, b->buffsize * 2 + 0x20);
            b->buffsize = b->buffsize * 2 + 0x20;
        }
        b->buffer[b->n] = (char)ls->current;
        b->n++;
        if (ls->z->n-- > 0)
            ls->current = (unsigned char)*ls->z->p++;
        else
            ls->current = FUN_0021a550(ls->z);
        count++;
    }
    return ls->current == s ? count : -count - 1;
}
