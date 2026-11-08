// STATUS: equivalent (tools/equiv.py level 3: 107 inputs, branch coverage 8/8)
// FUN_0033c0f0 @ 0x0033c0f0
// cl-flags: /GS
// string.char
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00212d70(LuaVMState* L);
extern "C" void __cdecl FUN_00339630(LuaVMState* L, LuaVMLBuffer* B);
extern "C" int __cdecl FUN_00339f70(LuaVMState* L, int narg);
extern "C" int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
extern "C" char* __cdecl FUN_00339470(LuaVMLBuffer* B);
extern "C" void __cdecl FUN_00339540(LuaVMLBuffer* B);

extern "C" int __cdecl FUN_0033c0f0(LuaVMState* L) {
    LuaVMLBuffer b;
    int n = FUN_00212d70(L);
    FUN_00339630(L, &b);
    for (int i = 1; i <= n; ++i) {
        int c = FUN_00339f70(L, i);
        if ((unsigned char)c != c)
            FUN_00339c30(L, i, "invalid value");
        if (b.p >= b.buffer + LUAVM_BUFFERSIZE)
            FUN_00339470(&b);
        *b.p = (char)(unsigned char)c;
        ++b.p;
    }
    FUN_00339540(&b);
    return 1;
}
