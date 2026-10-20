// FUN_00339590 @ 0x00339590
// FUN_00339590: Lua 5.0 lauxlib luaL_addvalue
#include "compat/ptr.h"
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct lua_State;
struct luaL_Buffer_339590 {
    char *p;
    int lvl;
    lua_State *L;
    char buffer[0x200];
};

unsigned int __cdecl FUN_002131f0(lua_State *L, int idx);              // lua_strlen
const char *__cdecl FUN_00213190(lua_State *L, int idx);               // lua_tostring
void __cdecl FUN_00212d80(lua_State *L, int idx);                      // lua_settop
void __cdecl FUN_00213380(lua_State *L, const char *s, unsigned int l); // lua_pushlstring
void __cdecl FUN_00212e20(lua_State *L, int idx);                      // lua_insert
void __cdecl FUN_003393f0(luaL_Buffer_339590 *B);                             // adjuststack

void FUN_00339590(luaL_Buffer_339590 *B)
{
    lua_State *L = B->L;
    unsigned int vl = FUN_002131f0(L, -1);
    if (vl <= (unsigned int)(&B->buffer[0x200] - B->p)) {
        memcpy(B->p, FUN_00213190(L, -1), vl);
        B->p += vl;
        FUN_00212d80(L, -2);
    } else {
        hulk_uintptr len = B->p - B->buffer;
        if (len != 0) {
            FUN_00213380(B->L, B->buffer, len);
            B->p = B->buffer;
            B->lvl++;
            FUN_00212e20(L, -2);
        }
        B->lvl++;
        FUN_003393f0(B);
    }
}
