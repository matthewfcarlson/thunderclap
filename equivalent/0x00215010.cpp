// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 0/0)
// luaE_newthread: a new thread linked after L, sharing its global state and globals table.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
// equiv-conv: FUN_00214dd0 edi esi
extern "C" void __cdecl FUN_00214dd0(LuaVMState* L, LuaVMState* L1);

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
