#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_002133d0(LuaVMState*, const char*);
extern "C" void __cdecl FUN_00213600(LuaVMState*, int);
// member (include/gen/owners.h C_1d2de0 +0x08) is the lua_State, an int member there: cast at the use.
int owners::C_1d2de0::FUN_001d2de0(hulk_intptr a, hulk_intptr b) {
    FUN_002133d0((LuaVMState*)(hulk_intptr)member, (const char*)a);
    FUN_00213600((LuaVMState*)(hulk_intptr)member, -2);
    return finish(((int)b));
}
