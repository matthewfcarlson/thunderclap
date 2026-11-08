// STATUS: equivalent (tools/equiv.py level 3: 2971 inputs, branch coverage 4/4)
// close_func: finish a function: close its locals, code the final RETURN, shrink the prototype's vectors to their
// use, unlink the FuncState and pop its anchors (re-anchoring the current name or string token).
#include "decls/data/lua.h"

// equiv-conv: FUN_0021c5b0 eax edx
extern "C" void FUN_0021c5b0(LuaVMLexState* ls, int tolevel);
extern "C" int __cdecl FUN_00220bd0(LuaVMFuncState* fs, unsigned int o, int a, unsigned int b,
                                    unsigned int c);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" LuaVMString* __cdecl FUN_0021b080(LuaVMLexState* ls, const char* str, unsigned int l);

extern "C" void __cdecl FUN_0021cb80(LuaVMLexState* ls) {
    LuaVMState* L = ls->L;
    LuaVMFuncState* fs = ls->fs;
    LuaVMProto* f = fs->f;

    FUN_0021c5b0(ls, 0);
    FUN_00220bd0(fs, 0x1b, 0, 1, 0); // OP_RETURN 0 1

    f->code =
        (LuaVMInstruction*)FUN_0021add0(L, f->code, f->sizecode * (unsigned int)sizeof(LuaVMInstruction),
                                        fs->pc * (unsigned int)sizeof(LuaVMInstruction));
    f->sizecode = fs->pc;

    f->lineinfo = (int*)FUN_0021add0(L, f->lineinfo, f->sizelineinfo * (unsigned int)sizeof(int),
                                     fs->pc * (unsigned int)sizeof(int));
    f->sizelineinfo = fs->pc;

    f->k = (LuaVMTObject*)FUN_0021add0(L, f->k, f->sizek * (unsigned int)sizeof(LuaVMTObject),
                                       fs->nk * (unsigned int)sizeof(LuaVMTObject));
    f->sizek = fs->nk;

    f->p = (LuaVMProto**)FUN_0021add0(L, f->p, f->sizep * (unsigned int)sizeof(LuaVMProto*),
                                      fs->np * (unsigned int)sizeof(LuaVMProto*));
    f->sizep = fs->np;

    f->locvars = (LuaVMLocVar*)FUN_0021add0(L, f->locvars, f->sizelocvars * (unsigned int)sizeof(LuaVMLocVar),
                                            fs->nlocvars * (unsigned int)sizeof(LuaVMLocVar));
    f->sizelocvars = fs->nlocvars;

    f->upvalues =
        (LuaVMString**)FUN_0021add0(L, f->upvalues, f->sizeupvalues * (unsigned int)sizeof(LuaVMString*),
                                    f->nups * (unsigned int)sizeof(LuaVMString*));
    f->sizeupvalues = f->nups;

    ls->fs = fs->prev;
    L->top -= 2;

    if (ls->t.token == 0x116 || ls->t.token == 0x11e)
        FUN_0021b080(ls, LUAVM_GETSTR(ls->t.seminfo.ts), ls->t.seminfo.ts->len);
}
