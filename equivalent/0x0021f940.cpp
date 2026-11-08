// STATUS: equivalent (tools/equiv.py level 3: 109 inputs, branch coverage 16/16)
// LoadVector: read n elements of size bytes into b, each reversed when the chunk's byte order differs.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" unsigned int __cdecl FUN_0021a610(LuaVMZio* z, void* b, unsigned int n);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);

// equiv-conv: FUN_0021f940 eax ecx edx stack
extern "C" void __cdecl FUN_0021f940(unsigned int n, unsigned char* b, LuaVMLoadState* S, unsigned int size) {
    if (!S->swap) {
        if (((int)FUN_0021a610(S->Z, b, n * size)))
            FUN_0021f800(S, "unexpected end of file");
        return;
    }
    if (!n)
        return;
    unsigned char* end = b + size - 1;
    do {
        unsigned char* out = end;
        unsigned int left = size;
        while (left) {
            LuaVMZio* z = S->Z;
            unsigned int previous = z->n;
            z->n = previous - 1;
            z = S->Z;
            int value;
            if (previous) {
                value = *(const unsigned char*)z->p;
                ++z->p;
            } else {
                value = FUN_0021a550(z);
            }
            if (value == -1)
                FUN_0021f800(S, "unexpected end of file");
            *out-- = (unsigned char)value;
            --left;
        }
        end += size;
    } while (--n);
}
