// STATUS: equivalent (tools/equiv.py level 3: 3101 inputs, branch coverage 18/20, incomplete)
// LoadHeader: signature, version 5.1, endianness (swap), the chunk format's sizes (4 each) and the test number.
#include "decls/data/lua.h"

// equiv-conv: FUN_00220220 eax
extern "C" void __cdecl FUN_00220220(LuaVMLoadState* S);
// equiv-conv: FUN_002202a0 eax edi stack
extern "C" void __cdecl FUN_002202a0(LuaVMLoadState* S, unsigned int expected, const char* what);
// equiv-conv: FUN_0021f8c0 ecx eax edx
extern "C" void __cdecl FUN_0021f8c0(char* b, unsigned int size, LuaVMLoadState* S);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);
extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);

// equiv-conv: FUN_00220310 eax
extern "C" void __cdecl FUN_00220310(LuaVMLoadState* S) {
    float x;
    int ch;
    unsigned int n;
    LuaVMZio* z;

    FUN_00220220(S);

    z = S->Z;
    n = z->n;
    z->n = n - 1;
    z = S->Z;
    if (n != 0) {
        const char* p = z->p;
        ch = *(const unsigned char*)p;
        z->p = p + 1;
    } else {
        ch = FUN_0021a550(z);
    }
    if (ch == -1)
        FUN_0021f800(S, "unexpected end of file");

    int version = (unsigned char)ch;
    if (version > 0x51)
        FUN_0021f800(S, "bad version (read %d.%d; expected at %s %d.%d)", version / 16, version % 16, "most", 5, 1);
    if (version < 0x51)
        FUN_0021f800(S, "bad version (read %d.%d; expected at %s %d.%d)", version / 16, version % 16, "least", 5, 1);

    z = S->Z;
    n = z->n;
    z->n = n - 1;
    z = S->Z;
    if (n != 0) {
        const char* p = z->p;
        ch = *(const unsigned char*)p;
        z->p = p + 1;
    } else {
        ch = FUN_0021a550(z);
    }
    if (ch == -1)
        FUN_0021f800(S, "unexpected end of file");

    S->swap = ((char)ch != 1);

    FUN_002202a0(S, 4, "int");
    FUN_002202a0(S, 4, "size_t");
    FUN_002202a0(S, 4, "instruction");
    FUN_002202a0(S, 4, "number");

    FUN_0021f8c0((char*)(void*)(&x), 4, S);
    if ((int)x != 0x1df5e76)
        FUN_0021f800(S, "unknown number format");
}
