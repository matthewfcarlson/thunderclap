// STATUS: equivalent (tools/equiv.py level 3: 441 inputs, branch coverage 20/20)
// newkey: insert a key into its main position (moving a colliding node that is not in its own main position to
// a free node), with the barrier; when no free node is left, rehash and look the key up again.
#include "decls/data/lua.h"

extern "C" LuaVMNode* __cdecl FUN_002198b0(const LuaVMTable* t, const LuaVMTObject* key);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);
extern "C" void __cdecl FUN_00219a60(const LuaVMTable* t, int* narray, int* nhash);
extern "C" int __cdecl FUN_00215f70(unsigned int x);
// equiv-conv: FUN_0021a0f0 eax ecx stack stack
extern "C" void __cdecl FUN_0021a0f0(int nasize, LuaVMTable* t, LuaVMState* L, int lsize);
extern "C" LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key);

extern "C" LuaVMTObject* __cdecl FUN_0021a3e0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key) {
    LuaVMNode* mp = FUN_002198b0(t, key);
    if (mp->i_val.tt != LUAVM_TNIL) {
        LuaVMNode* othern = FUN_002198b0(t, &mp->i_key);
        LuaVMNode* n = t->firstfree;
        if (othern != mp) {
            while (othern->next != mp)
                othern = othern->next;
            othern->next = n;
            *n = *mp;
            mp->next = 0;
            mp->i_val.tt = LUAVM_TNIL;
        } else {
            n->next = mp->next;
            mp->next = n;
            mp = n;
        }
    }
    LUAVM_SETOBJ(&mp->i_key, key);
    if (key->tt >= LUAVM_TSTRING && (key->value.gc->marked & 3) && (t->marked & 4))
        FUN_00217100(L, (LuaVMGCObject*)t, key->value.gc);
    if (t->firstfree->i_key.tt != LUAVM_TNIL) {
        LuaVMNode* first = t->node;
        while (t->firstfree != first) {
            --t->firstfree;
            if (t->firstfree->i_key.tt == LUAVM_TNIL)
                return &mp->i_val;
        }
        mp->i_val.value.b = 0;
        mp->i_val.tt = LUAVM_TBOOLEAN;
        int nasize;
        int nhsize;
        FUN_00219a60(t, &nasize, &nhsize);
        int lsize = FUN_00215f70((unsigned int)nhsize);
        FUN_0021a0f0(nasize, t, L, lsize + 1);
        LuaVMTObject* v = FUN_00219e90(t, key);
        v->tt = LUAVM_TNIL;
        return v;
    }
    return &mp->i_val;
}
