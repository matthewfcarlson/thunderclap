// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 8/8)
// FUN_00339e60 @ 0x00339e60
// luaL_optlstring
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212f00(LuaVMState* L, int idx);
extern "C" const char* __cdecl FUN_00339df0(LuaVMState* L, int narg, unsigned int* len);
extern "C" const char* __cdecl FUN_00339e60(LuaVMState* a, int b, const char* text, unsigned int* length)
{
    if (FUN_00212f00(a, b) > 0)
        return FUN_00339df0(a, b, length);
    if (length) {
        if (text) {
            const char* p = text;
            while (*p) ++p;
            *length = (unsigned int)(p - text);
        } else {
            *length = 0;
        }
    }
    return text;
}
