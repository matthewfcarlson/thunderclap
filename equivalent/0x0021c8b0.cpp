// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 8/8)
// adjust_assign: match nexps values to nvars targets (a call's results adjusted, missing values set to nil).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e,
                                     int nresults);                        // luaK_setcallreturns
extern "C" void __cdecl FUN_00220850(LuaVMFuncState* fs, int n);           // luaK_reserveregs
extern "C" void FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);         // luaK_exp2nextreg
extern "C" void __cdecl FUN_00220c40(LuaVMFuncState* fs, int from, int n); // luaK_nil

// equiv-conv: FUN_0021c8b0 eax ecx edx stack
extern "C" void FUN_0021c8b0(LuaVMLexState* ls, LuaVMExpDesc* e, int nexps, int nvars) {
    LuaVMFuncState* fs = ls->fs;
    int extra = nvars - nexps;
    if (e->k == 12) { // VCALL
        extra++;
        if (extra <= 0) {
            extra = 0;
            FUN_00220a50(fs, e, extra);
        } else {
            FUN_00220850(fs, extra - 1);
            FUN_00220a50(fs, e, extra);
        }
    } else {
        if (e->k != 0) // VVOID
            FUN_00221110(fs, e);
        if (extra > 0) {
            int reg = fs->freereg;
            FUN_00220850(fs, extra);
            FUN_00220c40(fs, reg, extra);
        }
    }
}
