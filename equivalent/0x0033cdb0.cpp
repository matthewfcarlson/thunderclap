// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033cdb0 @ 0x0033cdb0
// lstrlib gfind_aux (upvalues: the string, the pattern, the position)
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState* L, int idx);
extern "C" int __cdecl FUN_00213120(LuaVMState* L, int idx);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);
extern "C" void __cdecl FUN_00212e60(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_0033c7e0(LuaVMMatchState* ms, const char* s, const char* p);
// equiv-conv: FUN_0033cb70 esi ecx eax
int FUN_0033cb70(LuaVMMatchState* ms, const char* s, const char* e);

extern "C" int __cdecl FUN_0033cdb0(LuaVMState* L) {
    const char* s = FUN_00213190(L, -10002);
    unsigned int ls = FUN_002131f0(L, -10002);
    const char* p = FUN_00213190(L, -10003);
    LuaVMMatchState ms;
    ms.L = L;
    ms.src_init = s;
    ms.src_end = s + ls;
    const char* src = s + FUN_00213120(L, -10004);
    if (src > ms.src_end)
        return 0;
    const char* e;
    for (;;) {
        ms.level = 0;
        e = FUN_0033c7e0(&ms, src, p);
        if (e)
            break;
        ++src;
        if (src > ms.src_end)
            return 0;
    }
    int newstart = (int)(e - s);
    if (e == src)
        ++newstart;
    FUN_00213360(L, newstart);
    FUN_00212e60(L, -10004);
    return FUN_0033cb70(&ms, src, e);
}
