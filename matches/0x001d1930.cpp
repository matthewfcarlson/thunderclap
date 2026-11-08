#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" void __cdecl FUN_00213640(LuaVMState*, int, int);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
// m (include/gen/owners.h C_1d1930 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::C_1d1930::FUN_001d1930(int n) {
    if (n >= 1) {
        FUN_00213640((LuaVMState*)(hulk_intptr)m, -10000, n);
        if (FUN_00212f00((LuaVMState*)(hulk_intptr)m, -1) == 0) {
            FUN_00212d80((LuaVMState*)(hulk_intptr)m, -2);
            return false;
        }
        return true;
    }
    return false;
}
