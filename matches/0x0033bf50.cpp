// STATUS: equivalent (tools/equiv.py level 3: 84 inputs, branch coverage 6/6)
// FUN_0033bf50 @ 0x0033bf50
// cl-flags: /GS
// string.upper
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* B);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B);
extern "C" unsigned char __cdecl FUN_00345b90(unsigned character);
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* B);

extern "C" int __cdecl FUN_0033bf50(LuaVMState* L) {
    struct { unsigned int l; LuaVMLBuffer b; } local;
    const unsigned char* s = (const unsigned char*)FUN_00339df0(L, 1, &local.l);
    FUN_00339630(L, &local.b);
    for (unsigned i = 0; i < local.l; ++i) {
        if (local.b.p >= local.b.buffer + LUAVM_BUFFERSIZE)
            FUN_00339470(&local.b);
        unsigned char ch = FUN_00345b90(s[i]);
        *local.b.p = ch;
        ++local.b.p;
    }
    FUN_00339540(&local.b);
    return 1;
}
