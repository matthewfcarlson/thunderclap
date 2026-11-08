// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 2/2)
// block: enter a block, parse the chunk, then leave the block (close its locals and upvalues, patch its breaks).
#include "decls/data/lua.h"

// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void FUN_0021c5b0(LuaVMLexState* ls, int tolevel);
extern "C" void __cdecl FUN_0021f640(LuaVMLexState* ls);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C" void __cdecl FUN_00220d70(LuaVMFuncState* fs, int list);

// equiv-conv: FUN_0021e080 eax
extern "C" void FUN_0021e080(LuaVMLexState* ls) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMBlockCnt bl;

    bl.breaklist = -1;
    bl.isbreakable = 0;
    bl.nactvar = fs->nactvar;
    bl.upval = 0;
    bl.previous = fs->bl;
    fs->bl = &bl;

    FUN_0021f640(ls);

    LuaVMBlockCnt* b = fs->bl;
    fs->bl = b->previous;
    FUN_0021c5b0(fs->ls, b->nactvar);
    if (b->upval)
        FUN_00220bd0(fs, 0x22, b->nactvar, 0, 0); // OP_CLOSE
    fs->freereg = fs->nactvar;
    FUN_00220d70(fs, b->breaklist);
}
