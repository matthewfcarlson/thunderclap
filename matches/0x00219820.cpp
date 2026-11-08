// luaF_getlocalname: the name of the local_number-th local variable active at pc, or 0.
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00219820(const LuaVMProto* f, int local_number, int pc) {
    int i;
    for (i = 0; i < f->sizelocvars && f->locvars[i].startpc <= pc; i++) {
        if (pc < f->locvars[i].endpc) {
            local_number--;
            if (local_number == 0)
                return LUAVM_GETSTR(f->locvars[i].varname);
        }
    }
    return 0;
}
