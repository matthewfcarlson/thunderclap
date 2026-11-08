// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 10/10)
// luaK_exp2nextreg: put the expression into the next free register.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
// equiv-conv: FUN_00220fe0 eax stack stack
extern "C" int __cdecl FUN_00220fe0(LuaVMFuncState* fs, LuaVMExpDesc* e, int reg);

extern "C" void __cdecl FUN_00221110(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    FUN_00220d90(fs, e);
    if (e->k == 0xb && e->info >= fs->nactvar && e->info < 0xfa)
        fs->freereg--;
    int newstack = fs->freereg + 1;
    if (newstack > fs->f->maxstacksize) {
        if (newstack >= 0xfa)
            FUN_0021b060(fs->ls, "function or expression too complex");
        fs->f->maxstacksize = (unsigned char)newstack;
    }
    fs->freereg = fs->freereg + 1;
    FUN_00220fe0(fs, e, fs->freereg - 1);
}
