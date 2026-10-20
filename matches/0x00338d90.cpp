// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_00338d90 @ 0x00338d90
// cl-flags: /GS
#include "compat/ptr.h"
#include "decls/data/game/global.h"

struct lua_State;

struct lua_Debug_338d90 {
    int event;
    const char *name;
    const char *namewhat;
    const char *what;
    const char *source;
    int currentline;
    int nups;
    int linedefined;
    char short_src[60];
    int i_ci;
};


int __cdecl FUN_00213fc0(lua_State *L, int level, lua_Debug_338d90 *ar);
void __cdecl FUN_00213380(lua_State *L, const char *s, hulk_uintptr len);
const char *__cdecl FUN_00213470(lua_State *L, const char *fmt, ...);
int __cdecl FUN_00214bd0(lua_State *L, const char *what, lua_Debug_338d90 *ar);

// Lua 5.0 luaL_where: pushes "source:line: " for the given call level, or "".
void luaL_where(lua_State *L, int level)
{
    struct Frame {
        lua_Debug_338d90 ar;
    } f;

    if (FUN_00213fc0(L, level, &f.ar)) {
        FUN_00214bd0(L, "Sl", &f.ar);
        if (f.ar.currentline > 0) {
            FUN_00213470(L, "%s:%d: ", f.ar.short_src, f.ar.currentline);
            return;
        }
    }
    FUN_00213380(L, ((char*)&DAT_003f335c), 0);
}
