// luaK_self: e:key(...) puts the function and the object in two consecutive registers (OP_SELF).
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00221190(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" void __cdecl FUN_0021b060(LuaVMLexState* ls, const char* msg);
extern "C" int __cdecl FUN_00221200(LuaVMFuncState* fs, LuaVMExpDesc* e);
extern "C" int __cdecl FUN_00220b20(LuaVMFuncState* fs, LuaVMInstruction i, int line);

extern "C" void __cdecl FUN_00221360(LuaVMFuncState* fs, LuaVMExpDesc* e, LuaVMExpDesc* key) {
    FUN_00221190(fs, e);
    if (e->k == 11 && e->info >= fs->nactvar && e->info < 250)
        --fs->freereg;
    int func = fs->freereg;
    int required = func + 2;
    if (required > fs->f->maxstacksize) {
        if (required >= 250)
            FUN_0021b060(fs->ls, "function or expression too complex");
        fs->f->maxstacksize = (unsigned char)required;
    }
    fs->freereg += 2;
    unsigned int result = (unsigned int)FUN_00221200(fs, key);
    int line = fs->ls->lastline;
    LuaVMInstruction instruction = ((((unsigned int)func << 9) | (unsigned int)e->info) << 9 | result) << 6 | 11;
    FUN_00220b20(fs, instruction, line);
    if (key->k == 11 && key->info >= fs->nactvar && key->info < 250)
        --fs->freereg;
    e->info = func;
    e->k = 11;
}
