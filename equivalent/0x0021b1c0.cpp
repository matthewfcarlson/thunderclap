// STATUS: equivalent (tools/equiv.py level 3: 2948 inputs, branch coverage 4/4)
// save_and_next: append the current character to the buffer, then read the next one.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
// equiv-conv: FUN_0021b1c0 edi
extern "C" void FUN_0021b1c0(LuaVMLexState* ls) {
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
}
