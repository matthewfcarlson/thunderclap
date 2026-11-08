// STATUS: equivalent (tools/equiv.py level 3: 125 inputs, branch coverage 4/4)
// removevars: close the scope of the active locals above tolevel (their endpc is the current pc).
#include "decls/data/lua.h"

// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void FUN_0021c5b0(LuaVMLexState* ls, int tolevel) {
    LuaVMFuncState* fs = ls->fs;
    while (fs->nactvar > tolevel) {
        --fs->nactvar;
        fs->f->locvars[fs->actvar[fs->nactvar]].endpc = fs->pc;
    }
}
