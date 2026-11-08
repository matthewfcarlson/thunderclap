// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 6/6)
// lastlistfield: flush the constructor's pending array items (SETLISTO for an open call).
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e, int nresults);
extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);
extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e);

// cc arrives in esi, fs in edi.
// equiv-conv: FUN_0021cec0 esi edi
extern "C" void FUN_0021cec0(LuaVMConsControl* cc, LuaVMFuncState* fs) {
    if (cc->tostore == 0)
        return;
    if (cc->v.k == 12) { // VCALL
        FUN_00220a50(fs, &cc->v, -1);
        FUN_00220c10(fs, 0x21, cc->t->info, (unsigned int)(cc->na - 1)); // OP_SETLISTO
    } else {
        if (cc->v.k != 0)
            FUN_00221110(fs, &cc->v);
        FUN_00220c10(fs, 0x20, cc->t->info, (unsigned int)(cc->na - 1)); // OP_SETLIST
    }
    fs->freereg = cc->t->info + 1;
}
