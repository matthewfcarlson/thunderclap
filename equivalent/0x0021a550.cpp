// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// luaZ_fill: refill the stream's buffer from its reader; the first byte, or -1 at the end.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a550(LuaVMZio* z) {
    // the original keeps size in z's argument slot: a reader that does not write it leaves z's address there
    unsigned int size = (unsigned int)(hulk_uintptr)z;
    const char* buff = z->reader(z->L, z->data, &size);
    if (buff && size) {
        z->p = buff;
        z->n = size - 1;
        unsigned int c = *(const unsigned char*)buff;
        z->p = buff + 1;
        return (int)c;
    }
    return -1;
}
