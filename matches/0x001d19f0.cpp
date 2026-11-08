#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "decls/data/lua.h"
#include "gen/owners.h"

extern "C" const char* __cdecl FUN_00213190(LuaVMState* L, int idx);
extern "C" void FUN_00267760(char* buffer, unsigned int size, const char* format, ...);
extern "C" void __cdecl FUN_00212d80(LuaVMState* L, int idx);
// field (include/gen/owners.h Obj_1d19f0 +0x08) is the lua_State, an int member there, and a (the output
// buffer) is a hulk_intptr there: cast at the use.
bool owners::Obj_1d19f0::FUN_001d19f0(hulk_intptr a, int b, char flag) {
    const char* x = FUN_00213190((LuaVMState*)(hulk_intptr)field, -1);
    bool r = true;
    if (x == 0) {
        r = false;
    } else {
        FUN_00267760((char*)a, b, (const char*)&DAT_003f3f38, x);
    }
    if (flag)
        FUN_00212d80((LuaVMState*)(hulk_intptr)field, -2);
    return r;
}
