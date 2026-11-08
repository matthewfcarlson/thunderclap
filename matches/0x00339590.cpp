// FUN_00339590 @ 0x00339590
// FUN_00339590: Lua 5.0 lauxlib luaL_addvalue
#include "decls/data/lua.h"
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

extern "C" unsigned int __cdecl FUN_002131f0(LuaVMState *L, int idx);              // lua_strlen
extern "C" const char *__cdecl FUN_00213190(LuaVMState *L, int idx);               // lua_tostring
extern "C" void __cdecl FUN_00212d80(LuaVMState *L, int idx);                      // lua_settop
extern "C" void __cdecl FUN_00213380(LuaVMState *L, const char *s, unsigned int l); // lua_pushlstring
extern "C" void __cdecl FUN_00212e20(LuaVMState *L, int idx);                      // lua_insert
extern "C" void __cdecl FUN_003393f0(LuaVMLBuffer *B);                              // adjuststack

extern "C" void __cdecl FUN_00339590(LuaVMLBuffer *B)
{
    LuaVMState *L = B->L;
    unsigned int vl = FUN_002131f0(L, -1);
    if (vl <= (unsigned int)(&B->buffer[LUAVM_BUFFERSIZE] - B->p)) {
        memcpy(B->p, FUN_00213190(L, -1), vl);
        B->p += vl;
        FUN_00212d80(L, -2);
    } else {
        unsigned int len = (unsigned int)(B->p - B->buffer);
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
