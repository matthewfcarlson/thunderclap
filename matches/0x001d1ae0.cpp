#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#include "gen/owners.h"

extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" float __cdecl FUN_002130e0(LuaVMState*, int);
extern "C" int __cdecl FUN_00213160(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
// value (include/gen/owners.h Owner_1d1ae0 +0x08) is the lua_State, an int member there: cast at the use.
unsigned char owners::Owner_1d1ae0::FUN_001d1ae0(unsigned char* out) {
    unsigned char result = 1;
    int x = FUN_00212f00((LuaVMState*)(hulk_intptr)value, -1);
    switch (x) {
    case 0:
        *out = 0;
        break;
    case 1:
        *out = FUN_00213160((LuaVMState*)(hulk_intptr)value, -1) != 0;
        break;
    case 3: {
        int b;
        if ((*(float*)&DAT_003f32e0) != FUN_002130e0((LuaVMState*)(hulk_intptr)value, -1))
            b = 1;
        else
            b = 0;
        *out = b;
        break;
    }
    default:
        result = 0;
        break;
    }
    FUN_00212d80((LuaVMState*)(hulk_intptr)value, -2);
    return result;
}
