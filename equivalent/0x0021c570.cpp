// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 4/4)
// adjustlocalvars: activate the last nvars declared locals (their startpc is the current pc).
#include "decls/data/lua.h"

// equiv-conv: FUN_0021c570 eax edx
extern "C" void FUN_0021c570(LuaVMLexState* ls, int nvars) {
    LuaVMFuncState* fs = ls->fs;
    fs->nactvar = (unsigned char)(fs->nactvar + nvars);
    while (nvars != 0) {
        unsigned int index = (unsigned int)fs->nactvar - nvars;
        fs->f->locvars[fs->actvar[index]].startpc = fs->pc;
        --nvars;
    }
}
