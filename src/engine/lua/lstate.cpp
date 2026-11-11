// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00214dd0..0x00215240 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_f569808d {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f569808d {} using namespace fn_f569808d;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_f569808d {
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt);
extern "C" void __cdecl FUN_00214dd0(LuaVMState* L, LuaVMState* L1);
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash);
extern "C" void __cdecl FUN_002192e0(LuaVMState* L, int newsize);
extern "C" void __cdecl FUN_00217520(LuaVMState* L);
extern "C" void __cdecl FUN_0021aeb0(LuaVMState* L);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);
extern "C" void __cdecl FUN_00219660(LuaVMState* L, LuaVMStkId level);
extern "C" void __cdecl FUN_002172c0(LuaVMState* L);
extern "C" void __cdecl FUN_002192c0(LuaVMState* L);
extern "C" void __cdecl FUN_00214e80(LuaVMState* L, void* ud);
extern "C" int __cdecl FUN_002152f0(LuaVMState* L, void(__cdecl* f)(LuaVMState* L, void* ud), void* ud);
extern "C" void __cdecl FUN_00214f90(LuaVMState* L);
extern "C" void __cdecl FUN_00216f60(LuaVMState* L);
} // namespace fn_f569808d
extern "C" void _ReadWriteBarrier();
namespace fn_f569808d {
extern "C" unsigned int __cdecl FUN_002165c0(LuaVMState* L, int all);
extern "C" void __cdecl FUN_002151d0(LuaVMState* L, void* ud);


// 0x00214dd0 FUN_00214dd0 (123 B): equivalent/0x00214dd0.cpp
// sym: _FUN_00214dd0 @199bc4b1f140 @w6a6dd72cc3ed
// STATUS: equivalent (tools/equiv.py level 3: 2982 inputs, branch coverage 0/0)
// stack_init: allocate the value stack (BASIC_STACK_SIZE 40 + EXTRA_STACK 5) and the CallInfo array of thread L1.
// equiv-conv: FUN_00214dd0 edi esi
extern "C" void __cdecl FUN_00214dd0(LuaVMState* L, LuaVMState* L1) {
    LuaVMTObject* stack = (LuaVMTObject*)FUN_0021add0(L, 0, 0, 45 * (unsigned int)sizeof(LuaVMTObject));
    L1->stack = stack;
    L1->top = stack;
    L1->stacksize = 45;
    L1->stack_last = stack + 45 - 6;
    LuaVMCallInfo* ci = (LuaVMCallInfo*)FUN_0021add0(L, 0, 0, 8 * (unsigned int)sizeof(LuaVMCallInfo));
    L1->ci = ci;
    L1->base_ci = ci;
    L1->top->tt = LUAVM_TNIL;  // the function entry of the first CallInfo
    L1->top++;
    L1->ci->base = L1->top;
    L1->base = L1->ci->base;
    L1->ci->top = L1->top + 20;  // LUA_MINSTACK
    L1->end_ci = L1->base_ci + 8;
    L1->size_ci = 8;
}


// 0x00214e80 FUN_00214e80 (181 B): equivalent/0x00214e80.cpp
// sym: _FUN_00214e80 @562a475d551a @w3cecc43883fe
// STATUS: equivalent (tools/equiv.py level 3: 2965 inputs, branch coverage 0/0)
// f_luaopen: the protected part of lua_newstate: the udata list's dummy, the stack, the globals and registry tables,
// the string table, the tag-method names, the reserved words and the fixed memory-error message.
// equiv-conv: FUN_00214dd0 edi esi
extern "C" void __cdecl FUN_00214e80(LuaVMState* L, void* ud) {
    HULK_SIZE32(LuaVMUdata, 0x10);
    LuaVMUdata* u = (LuaVMUdata*)FUN_0021add0(L, 0, 0, sizeof(LuaVMUdata));
    u->len = 0;
    u->metatable = 0;
    L->l_G->firstudata = (LuaVMGCObject*)u;
    FUN_00217130(L, (LuaVMGCObject*)u, LUAVM_TUSERDATA);
    u->marked |= 0x20;  // fixed
    L->marked |= 0x20;
    FUN_00214dd0(L, L);
    LuaVMTable* t = FUN_00219cc0(L, 0, 4);
    L->_gt.value.gc = (LuaVMGCObject*)t;
    L->_gt.tt = LUAVM_TTABLE;
    LuaVMTObject* registry = &L->l_G->l_registry;
    t = FUN_00219cc0(L, 4, 4);
    registry->value.gc = (LuaVMGCObject*)t;
    registry->tt = LUAVM_TTABLE;
    FUN_002192e0(L, 0x2000);
    FUN_00217520(L);
    FUN_0021aeb0(L);
    LuaVMString* s = FUN_00219430(L, "not enough memory", 17);
    s->marked |= 0x20;
    LuaVMGlobal* g = L->l_G;
    g->GCthreshold = g->totalbytes << 2;
}


// 0x00214f90 FUN_00214f90 (114 B): equivalent/0x00214f90.cpp
// sym: _FUN_00214f90 @4cf235eec797 @w6a01d0469303
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 0/0)
// close_state: close the upvalues, free every object, the string table and the buffer, the main thread's stacks
// and the state block itself.
// equiv-conv: FUN_00214f90 esi
extern "C" void __cdecl FUN_00214f90(LuaVMState* L) {
    HULK_SIZE32(LuaVMLG, 0x108);
    LuaVMGlobal* g = L->l_G;
    FUN_00219660(L, L->stack);
    FUN_002172c0(L);
    FUN_002192c0(L);
    g->buff.buffer = (char*)FUN_0021add0(L, g->buff.buffer, g->buff.buffsize, 0);
    g->buff.buffsize = 0;
    FUN_0021add0(L, L->base_ci, (unsigned int)L->size_ci * (unsigned int)sizeof(LuaVMCallInfo), 0);
    FUN_0021add0(L, L->stack, (unsigned int)L->stacksize * (unsigned int)sizeof(LuaVMTObject), 0);
    g->frealloc(g->ud, L, sizeof(LuaVMLG), 0);
}


// 0x00215010 FUN_00215010 (120 B): equivalent/0x00215010.cpp
// sym: _FUN_00215010 @1a223280b0ef @w0ec319c9b30c
// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 0/0)
// luaE_newthread: a new thread linked after L, sharing its global state and globals table.
// equiv-conv: FUN_00214dd0 edi esi
extern "C" LuaVMState* __cdecl FUN_00215010(LuaVMState* L) {
    HULK_SIZE32(LuaVMState, 0x58);
    LuaVMState* L1 = (LuaVMState*)FUN_0021add0(L, 0, 0, sizeof(LuaVMState));
    L1->next = L->next;
    LuaVMGlobal* g = L->l_G;
    L->next = (LuaVMGCObject*)L1;
    L1->l_G = g;
    L1->tt = LUAVM_TTHREAD;
    L1->marked = *(unsigned char*)&g->currentwhite;
    L1->stack = 0;
    L1->stacksize = 0;
    L1->errorJmp = 0;
    L1->hook = 0;
    L1->hookmask = 0;
    L1->basehookcount = 0;
    L1->allowhook = 1;
    L1->hookcount = 0;
    L1->openupval = 0;
    L1->size_ci = 0;
    L1->nCcalls = 0;
    L1->status = 0;
    L1->ci = 0;
    L1->base_ci = 0;
    L1->errfunc = 0;
    L1->_gt.tt = LUAVM_TNIL;
    FUN_00214dd0(L, L1);
    LUAVM_SETOBJ(&L1->_gt, &L->_gt);
    return L1;
}


// 0x00215090 FUN_00215090 (76 B): matches/0x00215090.cpp
// sym: _FUN_00215090
// luaE_freethread: close L1's upvalues, then free its CallInfo array, its stack and the thread.
extern "C" void __cdecl FUN_00215090(LuaVMState* L, LuaVMState* L1) {
    HULK_SIZE32(LuaVMState, 0x58);
    FUN_00219660(L1, L1->stack);
    FUN_0021add0(L, L1->base_ci, (unsigned int)L1->size_ci * (unsigned int)sizeof(LuaVMCallInfo), 0);
    FUN_0021add0(L, L1->stack, (unsigned int)L1->stacksize * (unsigned int)sizeof(LuaVMTObject), 0);
    FUN_0021add0(L, L1, sizeof(LuaVMState), 0);
}


// 0x002150e0 FUN_002150e0 (233 B): equivalent/0x002150e0.cpp
// sym: _FUN_002150e0 @29eb73d96976 @w2c90d850ab7c
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 4/4)
// lua_newstate: allocate the main thread and its global state in one block, set them up, then f_luaopen protected.
// equiv-conv: FUN_00214f90 esi
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


// 0x002151d0 FUN_002151d0 (12 B): matches/0x002151d0.cpp
// sym: _FUN_002151d0
// callallgcTM: the protected body of lua_close's finalizer pass (luaC_callGCTM).
extern "C" void __cdecl FUN_002151d0(LuaVMState* L, void* ud) {
    FUN_00216f60(L);
}


// 0x002151e0 FUN_002151e0 (86 B): equivalent/0x002151e0.cpp
// sym: _FUN_002151e0 @f8a5663e37ea @w8c268d7b7b59
// STATUS: equivalent (tools/equiv.py level 3: 2548 inputs, branch coverage 2/2)
// lua_close: on the main thread: close the upvalues, separate the udata, run the finalizers (until none errs),
// then close_state.
// equiv-conv: FUN_00214f90 esi
extern "C" void __cdecl FUN_002151e0(LuaVMState* L) {
    L = L->l_G->mainthread;
    FUN_00219660(L, L->stack);
    FUN_002165c0(L, 1);
    L->errfunc = 0;
    int r;
    do {
        LuaVMCallInfo* ci = L->base_ci;
        L->ci = ci;
        LuaVMStkId base = ci->base;
        L->top = base;
        L->base = base;
        L->nCcalls = 0;
        r = FUN_002152f0(L, FUN_002151d0, 0);
    } while (r != 0);
    FUN_00214f90(L);
    _ReadWriteBarrier();
}

} // namespace fn_f569808d
