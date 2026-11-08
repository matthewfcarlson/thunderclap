// lua_dostring
#include "decls/data/lua.h"
extern "C" unsigned int __cdecl strlen(const char*);
extern "C" int __cdecl FUN_00339ba0(LuaVMState* L, const char* buff, unsigned int size, const char* name);
extern "C" int __cdecl FUN_00339c00(LuaVMState* p, const char* s) {
    return FUN_00339ba0(p, s, strlen(s), s);
}
