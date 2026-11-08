// STATUS: equivalent (tools/equiv.py level 3: 83 inputs, branch coverage 6/6)
// FUN_0033bde0 @ 0x0033bde0
// cl-flags: /GS
// string.reverse
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* B);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B);
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* B);

extern "C" int __cdecl FUN_0033bde0(LuaVMState* L) {
    unsigned int l;
    LuaVMLBuffer b;
    const char* s = FUN_00339df0(L, 1, &l);
    FUN_00339630(L, &b);
    if (l) {
        do {
            --l;
            if (b.p >= b.buffer + LUAVM_BUFFERSIZE)
                FUN_00339470(&b);
            *b.p = s[l];
            ++b.p;
        } while (l);
    }
    --l;
    FUN_00339540(&b);
    return 1;
}
