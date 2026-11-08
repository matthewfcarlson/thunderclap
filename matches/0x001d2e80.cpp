#include "decls/data/game/unknown.h"
#include "decls/data/lua.h"
#include "gen/owners.h"

extern "C" int __cdecl FUN_00212d70(LuaVMState*);
extern "C" void __cdecl FUN_00213380(LuaVMState*, const char*, unsigned int);
extern "C" void __cdecl FUN_00213600(LuaVMState*, int);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
// m is a void* member of include/gen/owners.h Obj_1d2e80: cast at the use.
bool owners::Obj_1d2e80::FUN_001d2e80() {
    int v = FUN_00212d70((LuaVMState*)m);
    F1d1cb0();
    FUN_00213380((LuaVMState*)m, DAT_003f8eb0, 5);
    FUN_00213600((LuaVMState*)m, -2);
    int r = FUN_00212f00((LuaVMState*)m, -1);
    if (r != 5) {
        FUN_00212d80((LuaVMState*)m, v);
        return false;
    }
    return true;
}
