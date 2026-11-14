// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// (regress, tri2) a tree TU whose block calls a __fastcall block of the same TU: clang puts both in one .text, and
// the call to `@FUN_00212bb0@8` must be bound to 0x00212bb0 (TREE_EXTERNAL), not taken for a local label of the
// section and run in place.
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L);
extern "C" const LuaVMTObject* __cdecl FUN_00217600(const LuaVMTObject* obj, LuaVMTObject* n);


// 0x00212bb0 FUN_00212bb0 (95 B): matches
// sym: @FUN_00212bb0@8
extern "C" LuaVMTObject* __fastcall FUN_00212bb0(int idx, LuaVMState* L) {
    if (idx > 0) {
        LuaVMTObject* o = L->base + (idx - 1);
        if (o < L->top)
            return o;
        return LUAVM_NILOBJECT;
    }
    if (idx > -10000)
        return L->top + idx;
    if (idx != -10001) {
        if (idx != -10000) {
            LuaVMCClosure* func = (LuaVMCClosure*)(L->base - 1)->value.gc;
            int i = -10001 - idx;
            LuaVMTObject* o = &func->upvalue[i - 1];
            return i <= func->nupvalues ? o : LUAVM_NILOBJECT;
        }
        return &L->l_G->l_registry;
    }
    return &L->_gt;
}


// 0x00212f70 FUN_00212f70 (51 B): equivalent
// sym: _FUN_00212f70
extern "C" int __cdecl FUN_00212f70(LuaVMState* L, int idx) {
    LuaVMTObject n;
    LuaVMTObject* o = FUN_00212bb0(idx, L);
    if (o->tt != LUAVM_TNUMBER && FUN_00217600(o, &n) == 0)
        return 0;
    return 1;
}
