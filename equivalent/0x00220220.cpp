// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 10/10)
// LoadSignature: the chunk starts with "\x1bLua".
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_0021a550(LuaVMZio* z);
// equiv-conv: FUN_0021f800 esi stack
extern "C" void __cdecl FUN_0021f800(LuaVMLoadState* S, const char* fmt, ...);

// equiv-conv: FUN_00220220 eax
extern "C" void __cdecl FUN_00220220(LuaVMLoadState* S) {
    const char* s = "\x1bLua";
    for (;;) {
        int c;
        if (S->Z->n-- > 0)
            c = *(const unsigned char*)S->Z->p++;
        else
            c = FUN_0021a550(S->Z);
        if (c == -1)
            FUN_0021f800(S, "unexpected end of file");
        if (c != *s)
            break;
        s++;
        if (*s == 0)
            return;
    }
    if (*s != 0)
        FUN_0021f800(S, "bad signature");
}
