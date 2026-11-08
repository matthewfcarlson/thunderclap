// luaX_newstring: intern a string and anchor it in the function's constant table (set to true when new).
#include "decls/data/lua.h"

extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" LuaVMTObject* __cdecl FUN_0021a500(LuaVMState* L, LuaVMTable* t, LuaVMString* key);
extern "C" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l) {
    LuaVMState* L = ls->L;
    LuaVMString* ts = FUN_00219430(L, str, l);
    LuaVMTObject* o = FUN_0021a500(L, ls->fs->h, ts);
    if (o->tt == LUAVM_TNIL) {
        o->value.b = 1;
        o->tt = LUAVM_TBOOLEAN;
    }
    return ts;
}
