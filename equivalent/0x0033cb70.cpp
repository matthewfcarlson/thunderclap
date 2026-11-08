// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 12/12)
// FUN_0033cb70 @ 0x0033cb70
// FUN_0033cb70 @ 0x0033cb70: Lua 5.0 lstrlib push_captures (push_onecapture inlined)
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00338fe0(LuaVMState *L, int space, const char *mes);
extern "C" int __cdecl FUN_00338e20(LuaVMState *L, const char *fmt, ...);
extern "C" void __cdecl FUN_00213380(LuaVMState *L, const char *s, unsigned int len);
extern "C" void __cdecl FUN_00213360(LuaVMState *L, int n);

// equiv-conv: FUN_0033cb70 esi ecx eax
int FUN_0033cb70(LuaVMMatchState *ms, const char *s, const char *e)
{
    FUN_00338fe0(ms->L, ms->level, "too many captures");
    if (ms->level == 0 && s) {
        FUN_00213380(ms->L, s, (unsigned int)(e - s));
        return 1;
    }
    for (int i = 0; i < ms->level; i++) {
        int l = ms->capture[i].len;
        if (l == LUAVM_CAP_UNFINISHED)
            FUN_00338e20(ms->L, "unfinished capture");
        if (l == LUAVM_CAP_POSITION)
            FUN_00213360(ms->L, (int)(ms->capture[i].init - ms->src_init + 1));
        else
            FUN_00213380(ms->L, ms->capture[i].init, (unsigned int)l);
    }
    return ms->level;
}
