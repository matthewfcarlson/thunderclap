#include "compat/ptr.h"
#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_00339710(LuaVMState* L, int t, int ref);
// field (include/gen/owners.h Obj_1d1900 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::Obj_1d1900::FUN_001d1900(hulk_intptr n) {
    if (((int)n) < 1)
        return false;
    FUN_00339710((LuaVMState*)(hulk_intptr)field, -10000, ((int)n));
    return true;
}
