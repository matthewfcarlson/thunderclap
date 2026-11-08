// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 7/8, incomplete)
// luaZ_lookahead: the next byte without consuming it (refilling an empty buffer), or -1 at the end.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a590(LuaVMZio* z) {
    if (z->n == 0) {
        // the original keeps size in z's argument slot: a reader that does not write it leaves z's address there
        unsigned int size = (unsigned int)(hulk_uintptr)z;
        const char* buff = z->reader(z->L, z->data, &size);
        if (buff == 0 || size == 0)
            return -1;
        z->p = buff;
        z->n = size - 1;
        z->p = buff + 1;
        z->n = size;
        z->p = buff;
    }
    return *(const unsigned char*)z->p;
}
