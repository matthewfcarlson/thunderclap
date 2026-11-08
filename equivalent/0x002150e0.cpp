// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// lua_newstate: allocate the main thread and its global state in one block, set them up, then f_luaopen protected.
#include "decls/data/lua.h"

extern "C" void __cdecl FUN_00214e80(LuaVMState* L, void* ud);
extern "C" int __cdecl FUN_002152f0(LuaVMState* L, void(__cdecl* f)(LuaVMState* L, void* ud), void* ud);
// equiv-conv: FUN_00214f90 esi
extern "C" void __cdecl FUN_00214f90(LuaVMState* L);

extern "C" LuaVMState* __cdecl FUN_002150e0(LuaVMAlloc f, void* ud) {
    HULK_SIZE32(LuaVMLG, 0x108);
    LuaVMState* L = (LuaVMState*)f(ud, 0, 0, sizeof(LuaVMLG));
    if (!L)
        return 0;
    LuaVMGlobal* g = &((LuaVMLG*)L)->g;
    L->next = 0;
    g->currentwhite = 1;
    L->l_G = g;
    L->tt = LUAVM_TTHREAD;
    L->marked = (unsigned char)g->currentwhite;
    L->stack = 0;
    L->stacksize = 0;
    L->errorJmp = 0;
    L->hook = 0;
    L->hookmask = 0;
    L->basehookcount = 0;
    L->allowhook = 1;
    L->hookcount = 0;
    L->openupval = 0;
    L->size_ci = 0;
    L->nCcalls = 0;
    L->status = 0;
    L->ci = 0;
    L->base_ci = 0;
    L->errfunc = 0;
    L->_gt.tt = LUAVM_TNIL;
    g->frealloc = f;
    g->ud = ud;
    g->mainthread = L;
    g->GCthreshold = 0;
    g->strt.size = 0;
    g->strt.nuse = 0;
    g->strt.hash = 0;
    L->l_G->l_registry.tt = LUAVM_TNIL;
    g->buff.buffer = 0;
    g->buff.buffsize = 0;
    g->panic = 0;
    g->gcstate = 3;
    g->rootgc = (LuaVMGCObject*)L;
    g->sweepstrgc = 0;
    g->sweepgc = &g->rootgc;
    g->firstudata = 0;
    g->gray = 0;
    g->grayagain = 0;
    g->weak = 0;
    g->tmudata = 0;
    g->dummynode[0].i_key.tt = LUAVM_TNIL;
    g->dummynode[0].i_val.tt = LUAVM_TNIL;
    g->dummynode[0].next = 0;
    g->totalbytes = sizeof(LuaVMLG);
    if (FUN_002152f0(L, FUN_00214e80, 0)) {
        FUN_00214f90(L);
        L = 0;
    }
    return L;
}
