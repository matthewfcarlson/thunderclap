#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "decls/data/lua.h"
#include "gen/owners.h"

extern "C" void __cdecl FUN_00213360(LuaVMState*, int);
extern "C" void __cdecl FUN_00213600(LuaVMState*, int);
extern "C" const char* __cdecl FUN_00213190(LuaVMState*, int);
extern void __cdecl F4(char*, int, const char*, const char*);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
// field (include/gen/owners.h C_1d2cd0 +0x08) is the lua_State, an int member there; b (the buffer) a hulk_intptr
// parameter there: cast at the use.
bool owners::C_1d2cd0::FUN_001d2cd0(int a, hulk_intptr b, int c) {
    FUN_00213360((LuaVMState*)(hulk_intptr)field, a);
    FUN_00213600((LuaVMState*)(hulk_intptr)field, -2);
    const char* r = FUN_00213190((LuaVMState*)(hulk_intptr)field, -1);
    bool ok = true;
    if (!r)
        ok = false;
    else
        F4((char*)b, c, (const char*)&DAT_003f3f38, r);
    FUN_00212d80((LuaVMState*)(hulk_intptr)field, -2);
    return ok;
}
