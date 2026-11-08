// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 10/10)
// FUN_0033c790 @ 0x0033c790
// lstrlib match_capture (check_capture inlined)
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);

// equiv-conv: FUN_0033c790 eax ecx ebx
const char *FUN_0033c790(int l, LuaVMMatchState *ms, const char *s)
{
    l -= 0x31;
    if (l < 0 || l >= ms->level || ms->capture[l].len == LUAVM_CAP_UNFINISHED)
        l = FUN_00338e20(ms->L, "invalid capture index");
    unsigned len = (unsigned)ms->capture[l].len;
    if ((unsigned)(ms->src_end - s) >= len) {
        const char *text = ms->capture[l].init;
        for (unsigned i = 0; i < len; ++i)
            if (text[i] != s[i]) return 0;
        return s + len;
    }
    return 0;
}
