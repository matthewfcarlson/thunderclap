// STATUS: equivalent (tools/equiv.py level 3: 2861 inputs, branch coverage 16/16)
// pushclosure: add the nested function's prototype to the parent's p, code its CLOSURE (v: VRELOCABLE) and one
// MOVE / GETUPVAL per upvalue.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021ae40(LuaVMState* L, void* block, int* size, int size_elem,
                                      int limit, const char* errormsg);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);
extern "C" int __cdecl FUN_00220c10(LuaVMFuncState* fs, unsigned int o, int a, unsigned int bc);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C" void __cdecl FUN_0021c9b0(LuaVMLexState* ls, LuaVMFuncState* func, LuaVMExpDesc* v) {
    LuaVMFuncState* fs = ls->fs;
    LuaVMProto* f = fs->f;
    int oldsize = f->sizep;
    if (fs->np + 1 > oldsize) {
        f->p = (LuaVMProto**)FUN_0021ae40(ls->L, f->p, &f->sizep, (int)sizeof(LuaVMProto*), 0x3ffff,
                                          "constant table overflow");
    }
    for (int i = oldsize; i < f->sizep; ++i)
        f->p[i] = 0;
    f->p[fs->np] = func->f;
    ++fs->np;
    if ((func->f->marked & 3) && (f->marked & 4))
        FUN_00217100(ls->L, (LuaVMGCObject*)f, (LuaVMGCObject*)func->f);
    int pc = FUN_00220c10(fs, 0x23, 0, (unsigned int)(fs->np - 1)); // OP_CLOSURE
    v->t = -1;
    v->f = -1;
    v->k = 10; // VRELOCABLE
    v->info = pc;
    for (int j = 0; j < func->f->nups; ++j) {
        // OP_MOVE for a local, OP_GETUPVAL for an upvalue
        FUN_00220bd0(fs, (unsigned int)(func->upvalues[j].k == 5 ? 0 : 4), 0,
                     (unsigned int)func->upvalues[j].info, 0);
    }
}
