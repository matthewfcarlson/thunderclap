#include "decls/data/lua.h"
#include "gen/owners.h"
typedef unsigned char u8;
extern "C" void __cdecl FUN_00213ba0(LuaVMState*, int, int);
// value (include/gen/owners.h Obj_1d15d0 +0x08) is the lua_State, an int member there: cast at the use.
void owners::Obj_1d15d0::FUN_001d15d0(char flag) {
    if (flag)
        FUN_00213ba0((LuaVMState*)(hulk_intptr)value, 2, 0);
    else
        FUN_00213ba0((LuaVMState*)(hulk_intptr)value, 4, 2);
}
