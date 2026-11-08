// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_0033e3f0 @ 0x0033e3f0
// luaB_newproxy
#include "decls/data/lua.h"

extern "C" {
void __cdecl FUN_00212d80(LuaVMState* L, int idx);
void* __cdecl FUN_00213d30(LuaVMState* L, unsigned int size);
int __cdecl FUN_00213160(LuaVMState* L, int idx);
int __cdecl FUN_00212f00(LuaVMState* L, int idx);
void __cdecl FUN_00213680(LuaVMState* L, int narray, int nrec);
void __cdecl FUN_00212ed0(LuaVMState* L, int idx);
void __cdecl FUN_00213520(LuaVMState* L, int b);
void __cdecl FUN_00213800(LuaVMState* L, int idx);
int __cdecl FUN_002138e0(LuaVMState* L, int objindex);
int __cdecl FUN_002136d0(LuaVMState* L, int objindex);
void __cdecl FUN_00213600(LuaVMState* L, int idx);
int __cdecl FUN_00339c30(LuaVMState* L, int narg, const char* extramsg);
}
extern "C" int __cdecl FUN_0033e3f0(LuaVMState* state)
{
    FUN_00212d80(state, 1);
    FUN_00213d30(state, 0);
    if (FUN_00213160(state, 1)) {
        if (FUN_00212f00(state, 1) == 1) {
            FUN_00213680(state, 0, 0);
            FUN_00212ed0(state, -1);
            FUN_00213520(state, 1);
            FUN_00213800(state, -10002);
            FUN_002138e0(state, 2);
            return 1;
        }
        int valid = 0;
        if (FUN_002136d0(state, 1)) {
            FUN_00213600(state, -10002);
            valid = FUN_00213160(state, -1);
            FUN_00212d80(state, -2);
        }
        if (!valid)
            FUN_00339c30(state, 1, "boolean or proxy expected");
        FUN_002136d0(state, 1);
        FUN_002138e0(state, 2);
    }
    return 1;
}
