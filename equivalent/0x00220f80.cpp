// STATUS: equivalent (tools/equiv.py level 3: 3006 inputs, branch coverage 6/6)
// discharge2anyreg: unless already in a register, reserve one and discharge the expression into it.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
// equiv-conv: FUN_00220e90 ebx esi edi
extern "C" void __cdecl FUN_00220e90(LuaVMExpDesc* e, unsigned int reg, LuaVMFuncState* fs);

// equiv-conv: FUN_00220f80 eax stack
extern "C" void __cdecl FUN_00220f80(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    if (e->k != 11) {
        int next = fs->freereg + 1;
        if (next > fs->f->maxstacksize) {
            if (next >= 250)
                FUN_0021b060(fs->ls, "function or expression too complex");
            fs->f->maxstacksize = (unsigned char)next;
        }
        fs->freereg = fs->freereg + 1;
        FUN_00220e90(e, (unsigned int)(fs->freereg - 1), fs);
    }
}
