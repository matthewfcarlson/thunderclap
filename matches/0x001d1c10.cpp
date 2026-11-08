#include "decls/data/lua.h"
#include "gen/owners.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" int __cdecl FUN_00213c50(LuaVMState*, int);
// obj (include/gen/owners.h C_1d1c10 +0x08) is the lua_State, an int member there: cast at the use.
bool owners::C_1d1c10::FUN_001d1c10(int p) {
    if (idx < 0)
        return false;
    int n = FUN_00212d70((LuaVMState*)(hulk_intptr)obj);
    int v = vals[idx];
    if (n != v + 1) {
        FUN_00212d80((LuaVMState*)(hulk_intptr)obj, v);
        return false;
    }
    return FUN_00213c50((LuaVMState*)(hulk_intptr)obj, p) != 0;
}
