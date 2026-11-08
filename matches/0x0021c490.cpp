// registerlocalvar: add a local variable's name to the prototype's locvars (growing it) and return its index.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021ae40(LuaVMState* L, void* block, int* size, int size_elem, int limit,
                                      const char* errormsg);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

extern "C" int __cdecl FUN_0021c490(LuaVMLexState* ls, LuaVMString* varname) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMProto* f = fs->f;
    int oldsize = f->sizelocvars;
    if (fs->nlocvars + 1 > oldsize)
        f->locvars = (LuaVMLocVar*)FUN_0021ae40(ls->L, f->locvars, &f->sizelocvars, (int)sizeof(LuaVMLocVar), 0xffff,
                                                "too many local variables");
    while (oldsize < f->sizelocvars)
        f->locvars[oldsize++].varname = 0;
    f->locvars[fs->nlocvars].varname = varname;
    if ((varname->marked & 3) && (f->marked & 4))
        FUN_00217100(ls->L, (LuaVMGCObject*)f, (LuaVMGCObject*)varname);
    return fs->nlocvars++;
}
