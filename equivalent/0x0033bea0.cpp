// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 6/6)
// FUN_0033bea0 @ 0x0033bea0
// cl-flags: /GS
// string.lower
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* B);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B);
extern "C" int __cdecl FUN_00345475(int);
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* B);

extern "C" int __cdecl FUN_0033bea0(LuaVMState* L) {
    unsigned int l;
    LuaVMLBuffer b;
    const unsigned char* s = (const unsigned char*)FUN_00339df0(L, 1, &l);
    FUN_00339630(L, &b);
    for (unsigned i = 0; i < l; ++i) {
        if (b.p >= b.buffer + LUAVM_BUFFERSIZE)
            FUN_00339470(&b);
        int c = FUN_00345475(s[i]);
        *b.p = (char)c;
        ++b.p;
    }
    FUN_00339540(&b);
    return 1;
}
