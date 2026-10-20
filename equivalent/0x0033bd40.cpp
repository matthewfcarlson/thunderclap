// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FUN_0033bd40 @ 0x0033bd40
// FUN_0033bd40: Lua string.sub
#include "compat/ptr.h"
struct lua_State;

const char *__cdecl FUN_00339df0(lua_State *L, int arg, unsigned int *len);
int __cdecl FUN_00339f70(lua_State *L, int arg);
int __cdecl FUN_00339fe0(lua_State *L, int arg, int def);
void __cdecl FUN_00213380(lua_State *L, const char *s, hulk_uintptr len);

int __cdecl FUN_0033bd40(lua_State *L)
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
        FUN_00213380(L, s + start - 1, end - start + 1);
    else
        FUN_00213380(L, "", 0);
    return 1;
}
