// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// TestSize: the chunk's size byte for a type must be the expected one (the chunk format's sizes).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);

// equiv-conv: FUN_002202a0 eax edi stack
extern "C" void __cdecl FUN_002202a0(LuaVMLoadState* S, unsigned int expected, const char* what) {
    LuaVMZio* z = S->Z;
    unsigned int count = z->n;
    z->n = count - 1;
    int value;
    if (count == 0) {
        value = FUN_0021a550(S->Z);
    } else {
        const char* cursor = S->Z->p;
        value = *(const unsigned char*)cursor;
        S->Z->p = cursor + 1;
    }
    if (value == -1)
        FUN_0021f800(S, "unexpected end of file");
    unsigned int byteValue = (unsigned char)value;
    if (byteValue != expected)
        FUN_0021f800(S, "bad size of %s (read %d; expected %d)", what, byteValue, expected);
}
