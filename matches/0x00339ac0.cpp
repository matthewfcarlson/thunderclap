// luaL_newstate
#include "decls/data/lua.h"
extern "C" void* __cdecl FUN_00339a90(void* ud, void* ptr, unsigned int osize, unsigned int nsize);
extern "C" LuaVMState* __cdecl FUN_002150e0(LuaVMAlloc f, void* ud);
extern "C" LuaVMState* __cdecl FUN_00339ac0(void) {
    return FUN_002150e0(FUN_00339a90, 0);
}
