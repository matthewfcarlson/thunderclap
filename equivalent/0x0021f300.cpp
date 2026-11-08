// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 2/2)
// exprstat: a call statement (no results) or an assignment.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021d830 eax esi
extern "C" void FUN_0021d830(LuaVMExpDesc* v, LuaVMLexState* ls);
extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e, int nresults);
extern "C" void __cdecl FUN_0021e170(LuaVMLexState* ls, LuaVMLHSAssign* lh, int nvars);
// equiv-conv: FUN_0021f300 eax
extern "C" void FUN_0021f300(LuaVMLexState* ls) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMLHSAssign v;
    FUN_0021d830(&v.v, ls);
    if (v.v.k == 12) { // VCALL
        FUN_00220a50(fs, &v.v, 0);
    } else {
        v.prev = 0;
        FUN_0021e170(ls, &v, 1);
    }
}
