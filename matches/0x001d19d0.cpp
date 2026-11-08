#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
// value (include/gen/owners.h Obj_1d19d0 +0x08) is the lua_State, an unsigned int member there: cast at the use.
unsigned char owners::Obj_1d19d0::FUN_001d19d0(unsigned int arg) {
    FUN_00212d80((LuaVMState*)(hulk_uintptr)value, (int)(0xffffffffu - arg));
    return 1;
}
