// STATUS: equivalent (tools/equiv.py level 3: 2965 inputs, branch coverage 0/0)
// f_luaopen: the protected part of lua_newstate: the udata list's dummy, the stack, the globals and registry tables,
// the string table, the tag-method names, the reserved words and the fixed memory-error message.
#include "decls/data/lua.h"

extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt);
// equiv-conv: FUN_00214dd0 edi esi
extern "C" void __cdecl FUN_00214dd0(LuaVMState* L, LuaVMState* L1);
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash);
extern "C" void __cdecl FUN_002192e0(LuaVMState* L, int newsize);
extern "C" void __cdecl FUN_00217520(LuaVMState* L);
extern "C" void __cdecl FUN_0021aeb0(LuaVMState* L);
extern "C" LuaVMString* __cdecl FUN_00219430(LuaVMState* L, const char* str, unsigned int l);

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
