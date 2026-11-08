// STATUS: equivalent (tools/equiv.py level 3: 157 inputs, branch coverage 8/8)
// FUN_0033c730 @ 0x0033c730
// lstrlib end_capture (capture_to_close inlined)
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" const char* __cdecl FUN_0033c7e0(LuaVMMatchState* ms, const char* s, const char* p);

// equiv-conv: FUN_0033c730 esi ebx stack
const char* FUN_0033c730(LuaVMMatchState* ms, const char* s, const char* p)
{
    int l = ms->level - 1;
    while (l >= 0 && ms->capture[l].len != LUAVM_CAP_UNFINISHED)
        --l;
    if (l < 0)
        l = FUN_00338e20(ms->L, "invalid pattern capture");
    ms->capture[l].len = (int)(s - ms->capture[l].init);
    const char* res = FUN_0033c7e0(ms, s, p);
    if (res == 0)
        ms->capture[l].len = LUAVM_CAP_UNFINISHED;
    return res;
}
