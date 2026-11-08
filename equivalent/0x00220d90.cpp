// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 18/18)
// luaK_dischargevars: turn a variable expression (local, upvalue, global, indexed, call) into a value.
#include "decls/data/lua.h"

extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b, unsigned int c);
extern "C" void __cdecl FUN_00220a50(LuaVMFuncState* fs, LuaVMExpDesc* e, int nresults);

extern "C" void __cdecl FUN_00220d90(LuaVMFuncState* fs, LuaVMExpDesc* e) {
    switch (e->k) {
    case 5:
        e->k = 11;
        break;
    case 6:
        e->info = FUN_00220bd0(fs, 4, 0, (unsigned int)e->info, 0);
        e->k = 10;
        break;
    case 7:
        e->info = FUN_00220c10(fs, 5, 0, (unsigned int)e->info);
        e->k = 10;
        break;
    case 8: {
        int limit = fs->nactvar;
        if (e->aux >= limit && e->aux < 250)
            --fs->freereg;
        if (e->info >= limit && e->info < 250)
            --fs->freereg;
        e->info = FUN_00220bd0(fs, 6, 0, (unsigned int)e->info, (unsigned int)e->aux);
        e->k = 10;
        break;
    }
    case 12:
        FUN_00220a50(fs, e, 1);
        break;
    }
}
