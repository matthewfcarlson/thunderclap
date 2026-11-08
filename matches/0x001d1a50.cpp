#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_002133d0(LuaVMState*, const char*);
// member (include/gen/owners.h C_1d1a50 +0x08) is the lua_State, an unsigned int member there: cast at the use.
bool owners::C_1d1a50::FUN_001d1a50(hulk_uintptr arg) {
    FUN_002133d0((LuaVMState*)(hulk_uintptr)member, (const char*)arg);
    return true;
}
