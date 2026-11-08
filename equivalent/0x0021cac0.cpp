// STATUS: equivalent (tools/equiv.py level 3: 2942 inputs, branch coverage 4/4)
// open_func: start a function: a new prototype and constant table, the FuncState linked on the lexer, both
// anchored on the stack.
#include "decls/data/lua.h"

extern "C" LuaVMProto* __cdecl FUN_002196d0(LuaVMState* L);
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash);
extern "C" void __cdecl FUN_00215460(LuaVMState* L, int n);
// equiv-conv: FUN_0021cac0 ecx eax
extern "C" void FUN_0021cac0(LuaVMLexState* ls, LuaVMFuncState* fs) {
    LuaVMState* L = ls->L;
    LuaVMProto* f = FUN_002196d0(L);
    fs->f = f;
    fs->prev = ls->fs;
    fs->ls = ls;
    fs->L = L;
    ls->fs = fs;
    fs->pc = 0;
    fs->lasttarget = 0;
    fs->jpc = -1;
    fs->freereg = 0;
    fs->nk = 0;
    fs->np = 0;
    fs->nlocvars = 0;
    fs->nactvar = 0;
    fs->bl = 0;
    f->source = ls->source;
    f->maxstacksize = 2;
    LuaVMTable* h = FUN_00219cc0(L, 0, 0);
    fs->h = h;
    LuaVMTObject* o = L->top;
    o->value.gc = (LuaVMGCObject*)h;
    o->tt = LUAVM_TTABLE;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    o = L->top + 1;
    L->top = o;
    o->value.gc = (LuaVMGCObject*)f;
    o->tt = LUAVM_TPROTO;
    if ((char*)L->stack_last - (char*)L->top <= (int)sizeof(LuaVMTObject))
        FUN_00215460(L, 1);
    ++L->top;
}
