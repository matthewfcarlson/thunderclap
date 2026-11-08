// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 10/10)
// FUN_0033bd40 @ 0x0033bd40
// FUN_0033bd40: Lua string.sub
#include "decls/data/lua.h"

extern "C" const char *__cdecl FUN_00339df0(LuaVMState *L, int narg, unsigned int *len);
extern "C" int __cdecl FUN_00339f70(LuaVMState *L, int narg);
extern "C" int __cdecl FUN_00339fe0(LuaVMState *L, int narg, int def);
extern "C" void __cdecl FUN_00213380(LuaVMState *L, const char *s, unsigned int len);

extern "C" int __cdecl FUN_0033bd40(LuaVMState *L)
{
    unsigned int l;
    const char *s = FUN_00339df0(L, 1, &l);
    int start = FUN_00339f70(L, 2);
    if (start < 0)
        start = (int)l + start + 1;
    int end = FUN_00339fe0(L, 3, -1);
    if (end < 0)
        end = end + (int)l + 1;
    if (start < 1)
        start = 1;
    if (end > (int)l)
        end = (int)l;
    if (start <= end)
        FUN_00213380(L, s + start - 1, (unsigned int)(end - start + 1));
    else
        FUN_00213380(L, "", 0);
    return 1;
}
