// STATUS: equivalent (tools/equiv.py level 3: 2872 inputs, branch coverage 14/14)
// addk (float-number build): find or append constant v, keyed by k, in the prototype's constant table.
// fs arrives in ebx and k in ecx; v is on the stack.
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __cdecl FUN_00219ef0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);
extern "C" void* __cdecl FUN_0021ae40(LuaVMState* L, void* block, int* size, int size_elem, int limit,
                                      const char* errormsg);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);

// equiv-conv: FUN_0034483c
// equiv-conv: FUN_002208e0 ebx ecx stack
extern "C" int __cdecl FUN_002208e0(LuaVMFuncState* fs, LuaVMTObject* k, LuaVMTObject* v) {
    LuaVMState* L = fs->L;
    LuaVMTObject* idx = FUN_00219ef0(L, fs->h, k);
    LuaVMProto* f = fs->f;
    int oldsize = f->sizek;
    if (idx->tt == LUAVM_TNUMBER) {
        return (int)idx->value.n;
    } else {
        idx->tt = LUAVM_TNUMBER;
        idx->value.n = (float)fs->nk;
        if (fs->nk + 1 > f->sizek)
            f->k = (LuaVMTObject*)FUN_0021ae40(L, f->k, &f->sizek, (int)sizeof(LuaVMTObject), 0x3ffff,
                                               "constant table overflow");
        while (oldsize < f->sizek) {
            f->k[oldsize].tt = LUAVM_TNIL;
            oldsize++;
        }
        LuaVMTObject* slot = &f->k[fs->nk];
        LUAVM_SETOBJ(slot, v);
        if (v->tt >= LUAVM_TSTRING && (v->value.gc->marked & 3) && (f->marked & 4))
            FUN_00217100(L, (LuaVMGCObject*)f, v->value.gc);
        return fs->nk++;
    }
}
