// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 4/4)
// FUN_0033cb10 @ 0x0033cb10
// lstrlib push_onecapture
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00338e20(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00213360(LuaVMState* L, int n);
extern "C" void __cdecl FUN_00213380(LuaVMState* L, const char* s, unsigned int len);

// equiv-conv: FUN_0033cb10 eax esi
void FUN_0033cb10(int i, LuaVMMatchState* ms)
{
    int l = ms->capture[i].len;
    if (l == LUAVM_CAP_UNFINISHED)
        FUN_00338e20(ms->L, "unfinished capture");
    else if (l == LUAVM_CAP_POSITION) {
        FUN_00213360(ms->L, (int)(ms->capture[i].init - ms->src_init) + 1);
        return;
    }
    FUN_00213380(ms->L, ms->capture[i].init, (unsigned int)l);
}
