// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 12/12)
// LoadBlock: read size bytes into b, reversed when the chunk's byte order differs.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
extern "C" unsigned int __cdecl FUN_0021a610(LuaVMZio* z, void* b, unsigned int n);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);

// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S) {
    if (S->swap == 0) {
        if (((int)FUN_0021a610(S->Z, b, size)) != 0)
            FUN_0021f800(S, "unexpected end of file");
        return;
    }
    char* dst = b + size - 1;
    for (; size != 0; size--) {
        int c;
        if (S->Z->n-- > 0)
            c = *(const unsigned char*)S->Z->p++;
        else
            c = FUN_0021a550(S->Z);
        if (c == -1)
            FUN_0021f800(S, "unexpected end of file");
        *dst-- = (char)c;
    }
}
