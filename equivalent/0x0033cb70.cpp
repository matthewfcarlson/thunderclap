// STATUS: equivalent (tools/equiv.py level 3: 2417 inputs, branch coverage 12/12)
// FUN_0033cb70 @ 0x0033cb70
// FUN_0033cb70 @ 0x0033cb70: Lua 5.0 lstrlib push_captures (push_onecapture inlined)
#include "compat/ptr.h"
struct lua_State;

struct Capture_33cb70 {
    const char *init;
    int len;
};

struct MatchState_33cb70 {
    const char *src_init;   // 0x00
    const char *src_end;    // 0x04
    lua_State *L;           // 0x08
    int level;              // 0x0c
    Capture_33cb70 capture[32];    // 0x10
};

void __cdecl FUN_00338fe0(lua_State *L, int space, const char *msg);
void __cdecl FUN_00338e20(lua_State *L, const char *fmt, ...);
void __cdecl FUN_00213380(lua_State *L, const char *s, hulk_uintptr len);
void __cdecl FUN_00213360(lua_State *L, int n);

// equiv-conv: FUN_0033cb70 esi ecx eax
int FUN_0033cb70(MatchState_33cb70 *ms, const char *s, const char *e)
{
    FUN_00338fe0(ms->L, ms->level, "too many captures");
    if (ms->level == 0 && s) {
        FUN_00213380(ms->L, s, e - s);
        return 1;
    }
    for (int i = 0; i < ms->level; i++) {
        int l = ms->capture[i].len;
        if (l == -1)
            FUN_00338e20(ms->L, "unfinished capture");
        if (l == -2)
            FUN_00213360(ms->L, (int)(ms->capture[i].init - ms->src_init + 1));
        else
            FUN_00213380(ms->L, ms->capture[i].init, l);
    }
    return ms->level;
}
