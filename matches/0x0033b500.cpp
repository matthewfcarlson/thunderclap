// luaB_sort
#include "decls/data/lua.h"
#include "decls/data/game/global.h"
// data: gZero_33b500 = DAT_003f335c

extern "C" void __cdecl FUN_00339d70(LuaVMState*, int, int);
extern "C" int __cdecl FUN_003392c0(LuaVMState*, int);
extern "C" void __cdecl FUN_00338fe0(LuaVMState*, int, const char*);
extern "C" int __cdecl FUN_00212f00(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" void __cdecl FUN_0033b110(LuaVMState*, int, int);
extern "C" int __cdecl FUN_0033b500(LuaVMState* p) {
    FUN_00339d70(p, 1, 5);
    int v = FUN_003392c0(p, 1);
    FUN_00338fe0(p, 0x28, (const char*)&DAT_003f335c);
    int n = FUN_00212f00(p, 2);
    if (n > 0)
        FUN_00339d70(p, 2, 6);
    FUN_00212d80(p, 2);
    FUN_0033b110(p, 1, v);
    return 0;
}
