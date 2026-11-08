// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 4/4)
// FUN_00339270 @ 0x00339270
// luaL_setn
#include "decls/data/lua.h"
extern "C" int __cdecl FUN_00212d70(LuaVMState*);
// equiv-conv: FUN_003391f0 esi
extern "C" void __cdecl FUN_003391f0(LuaVMState*);
extern "C" void __cdecl FUN_00212ed0(LuaVMState*, int);
extern "C" void __cdecl FUN_00213360(LuaVMState*, int);
extern "C" void __cdecl FUN_00213800(LuaVMState*, int);
extern "C" void __cdecl FUN_00212d80(LuaVMState*, int);
extern "C" void __cdecl FUN_00339270(LuaVMState* a, int b, int c) {
    if (b <= 0 && b > -10000)
        b = b + 1 + FUN_00212d70(a);
    FUN_003391f0(a);
    FUN_00212ed0(a, b);
    FUN_00213360(a, c);
    FUN_00213800(a, -3);
    FUN_00212d80(a, -2);
}
