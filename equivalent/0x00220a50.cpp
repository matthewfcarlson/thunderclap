// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 4/4)
// luaK_setcallreturns: set a call's result count (C = nresults + 1); one result makes it a VNONRELOC in A.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e, int nresults) {
    if ((unsigned int)e->k != 12)
        return;
    LuaVMInstruction& word = fs->f->code[e->info];
    word ^= (((nresults + 1) << 6) ^ word) & 0x7fc0;
    if (nresults == 1) {
        e->k = 11;
        e->info = ((unsigned char*)&fs->f->code[e->info])[3];
    }
}
