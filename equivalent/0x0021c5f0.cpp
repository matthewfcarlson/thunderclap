// STATUS: equivalent (tools/equiv.py level 3: 2980 inputs, branch coverage 22/22)
// indexupvalue: the index of the upvalue v of the function (added, with its name, when new).
#include "decls/data/lua.h"

extern "C" const char* __cdecl FUN_00216320(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_0021afd0(LuaVMLexState* ls, const char* msg, int token);
extern "C" void* __cdecl FUN_0021ae40(LuaVMState* L, void* block, int* size, int size_elem,
                                      int limit, const char* errormsg);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

// fs arrives in edi, name and v on the stack.
// equiv-conv: FUN_0021c5f0 edi stack stack
extern "C" int FUN_0021c5f0(LuaVMFuncState* fs, LuaVMString* name, LuaVMExpDesc* v) {
    LuaVMProto* f = fs->f;
    int i;
    int oldsize;

    oldsize = f->sizeupvalues;
    for (i = 0; i < f->nups; i++) {
        if (fs->upvalues[i].k == v->k && fs->upvalues[i].info == v->info)
            return i;
    }

    if (f->nups + 1 > LUAVM_MAXUPVALUES) {
        const char* msg;
        if (f->lineDefined == 0)
            msg = FUN_00216320(fs->L, "main function has more than %d %s", 32, "upvalues");
        else
            msg = FUN_00216320(fs->L, "function at line %d has more than %d %s", f->lineDefined, 32,
                               "upvalues");
        FUN_0021afd0(fs->ls, msg, 0);
    }

    if (f->nups + 1 > f->sizeupvalues)
        f->upvalues = (LuaVMString**)FUN_0021ae40(fs->L, f->upvalues, &f->sizeupvalues, (int)sizeof(LuaVMString*),
                                                  0x7ffffffd, "");
    while (oldsize < f->sizeupvalues)
        f->upvalues[oldsize++] = 0;

    f->upvalues[f->nups] = name;
    if ((name->marked & 3) && (f->marked & 4))
        FUN_00217100(fs->L, (LuaVMGCObject*)f, (LuaVMGCObject*)name);
    fs->upvalues[f->nups].k = (unsigned char)v->k;
    fs->upvalues[f->nups].info = (unsigned char)v->info;
    return f->nups++;
}
