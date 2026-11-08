// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// checkSizes: halve the string table when a quarter full and the concatenation buffer when over 64 bytes.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_002192e0(LuaVMState* L, int newsize);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);

// equiv-conv: FUN_00216e70 ebx
extern "C" void __cdecl FUN_00216e70(LuaVMState* L) {
    LuaVMGlobal* g = L->l_G;
    if (g->strt.nuse < (unsigned int)(g->strt.size / 4) && g->strt.size > 0x4000)
        FUN_002192e0(L, g->strt.size / 2);
    unsigned int size = g->buff.buffsize;
    if (size > 0x40) {
        unsigned int newsize = size >> 1;
        char* buffer = (char*)FUN_0021add0(L, g->buff.buffer, size, newsize);
        g->buff.buffsize = newsize;
        g->buff.buffer = buffer;
    }
}
