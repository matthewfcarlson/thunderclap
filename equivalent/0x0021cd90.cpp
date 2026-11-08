// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 4/4)
// recfield: name = exp or [exp] = exp in a table constructor (OP_SETTABLE); returns the instruction's pc.
#include "decls/data/lua.h"

// equiv-conv: FUN_0021c240 esi ecx edx
extern "C" void FUN_0021c240(LuaVMFuncState* fs, const char* what, int limit);
// equiv-conv: FUN_0021c3d0 esi
extern "C" LuaVMString* FUN_0021c3d0(LuaVMLexState* ls);
extern "C" int __cdecl FUN_002209b0(LuaVMFuncState* fs, LuaVMString* s);
// equiv-conv: FUN_0021cd30 eax edi
extern "C" void FUN_0021cd30(LuaVMLexState* ls, LuaVMExpDesc* v);
// equiv-conv: FUN_0021c2e0 esi eax
extern "C" void FUN_0021c2e0(LuaVMLexState* ls, int c);
extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_0021ded0(LuaVMLexState* ls, LuaVMExpDesc* v, unsigned int limit);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C" int __cdecl FUN_0021cd90(LuaVMLexState* ls, LuaVMConsControl* cc) {
    LuaVMFuncState* fs = ls->fs;
    int reg = fs->freereg;
    LuaVMExpDesc key, val;
    if (ls->t.token == 0x116) {
        if (cc->nh > 0x7ffffffd)
            FUN_0021c240(fs, "items in a constructor", 0x7ffffffd);
        ++cc->nh;
        LuaVMString* name = FUN_0021c3d0(ls);
        int info = FUN_002209b0(ls->fs, name);
        key.t = -1;
        key.f = -1;
        key.k = 4; // VK
        key.info = info;
    } else
        FUN_0021cd30(ls, &key);
    FUN_0021c2e0(ls, 0x3d);
    FUN_00221200(fs, &key);
    FUN_0021ded0(ls, &val, 0);
    int rkval = FUN_00221200(fs, &val);
    int rkkey = FUN_00221200(fs, &key);
    int pc = FUN_00220bd0(fs, 9, cc->t->info, (unsigned int)rkkey, (unsigned int)rkval); // OP_SETTABLE
    fs->freereg = reg;
    return pc;
}
