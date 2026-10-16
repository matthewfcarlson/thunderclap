// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_0033ea90 @ 0x0033ea90
#include "decls/data/engine/unknown.h"

struct lua_State;
typedef int (*lua_CFunction)(lua_State *L);

struct luaL_Reg {
    const char *name;
    lua_CFunction func;
};


void FUN_00212ed0(lua_State *L, int idx);
void FUN_003390d0(lua_State *L, const char *libname, const luaL_Reg *l, int nup);
void FUN_00213380(lua_State *L, const char *s, unsigned int len);
void FUN_00213790(lua_State *L, int idx, const char *k);
void FUN_00213680(lua_State *L, int narr, int nrec);
void FUN_002138e0(lua_State *L, int idx);
void FUN_002134a0(lua_State *L, lua_CFunction fn, int n);
int FUN_0033e3f0(lua_State *L);

// luaopen_base: the Lua state is passed in esi
// equiv-conv: FUN_0033ea90 esi
void FUN_0033ea90(lua_State *L)
{
    FUN_00212ed0(L, -10001);
    FUN_003390d0(L, 0, ((luaL_Reg*)&DAT_00434d90), 0);
    FUN_00213380(L, "Lua 5.1 (work)", 14);
    FUN_00213790(L, -2, "_VERSION");
    FUN_00213680(L, 0, 0);
    FUN_00212ed0(L, -1);
    FUN_002138e0(L, -2);
    FUN_00213380(L, "kv", 2);
    FUN_00213790(L, -2, "__mode");
    FUN_002134a0(L, FUN_0033e3f0, 1);
    FUN_00213790(L, -2, "newproxy");
    FUN_00213790(L, -1, "_G");
}
