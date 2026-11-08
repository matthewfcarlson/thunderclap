// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_0033c6e0 @ 0x0033c6e0
// lstrlib start_capture
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" const char* __cdecl FUN_0033c7e0(LuaVMMatchState* ms, const char* s, const char* p);

// equiv-conv: FUN_0033c6e0 esi ebx stack stack
const char* FUN_0033c6e0(LuaVMMatchState* ms, const char* s, const char* p, int what)
{
    int level = ms->level;
    if (level >= LUAVM_MAXCAPTURES)
        FUN_00338e20(ms->L, "too many captures");
    ms->capture[level].init = s;
    ms->capture[level].len = what;
    ms->level = level + 1;
    const char* res = FUN_0033c7e0(ms, s, p);
    if (!res)
        --ms->level;
    return res;
}
