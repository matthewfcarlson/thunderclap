// STATUS: equivalent (tools/equiv.py level 3: 541 inputs, branch coverage 13/14, incomplete)
// luaZ_read: copy n bytes out of the stream into b; the number of bytes missing.
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#include "decls/data/lua.h"

extern "C" unsigned int __cdecl FUN_0021a610(LuaVMZio* z, void* b, unsigned int n) {
    while (n != 0) {
        if (z->n == 0) {
            unsigned int size;
            const char* buff = z->reader(z->L, z->data, &size);
            if (buff == 0 || size == 0)
                return n;
            z->n = size - 1;
            z->p = buff;
            int c = *(const unsigned char*)z->p++;
            if (c == -1)
                return n;
            z->n++;
            z->p--;
        }
        unsigned int m = (n <= z->n) ? n : z->n;
        memcpy(b, z->p, m);
        z->n -= m;
        z->p += m;
        b = (char*)b + m;
        n -= m;
    }
    return 0;
}
