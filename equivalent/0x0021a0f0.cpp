// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 25/46, incomplete)
// resize: give a table nasize array slots and 2^lsize nodes, re-inserting the values that moved.
#include "decls/data/engine/unknown.h"
#include "decls/data/lua.h"

// equiv-conv: FUN_00219be0 esi edi stack
extern "C" void __cdecl FUN_00219be0(LuaVMTable* t, int size, LuaVMState* L);
// equiv-conv: FUN_00219c30 ebx esi stack
extern "C" void __cdecl FUN_00219c30(LuaVMState* L, LuaVMTable* t, int lsize);
extern "C" LuaVMTObject* __cdecl FUN_00219dc0(LuaVMTable* t, int key);
extern "C" LuaVMTObject* __cdecl FUN_0021a3e0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" LuaVMNode* __cdecl FUN_002198b0(const LuaVMTable* t, const LuaVMTObject* key);
extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);

// equiv-conv: FUN_0021a0f0 eax ecx stack stack
extern "C" void __cdecl FUN_0021a0f0(int nasize, LuaVMTable* t, LuaVMState* L, int lsize) {
    int oldasize = t->sizearray;
    int oldlsize = t->lsizenode;
    LuaVMNode* nold;
    LuaVMNode temp[1];
    LuaVMTObject key;

    if (oldlsize == 0) {
        temp[0] = *t->node;
        L->l_G->dummynode->i_key.tt = LUAVM_TNIL;
        nold = temp;
        L->l_G->dummynode->i_val.tt = LUAVM_TNIL;
    } else {
        nold = t->node;
    }

    if (nasize > oldasize)
        FUN_00219be0(t, nasize, L);
    FUN_00219c30(L, t, lsize);

    if (nasize < oldasize) {
        t->sizearray = nasize;
        for (int i = nasize; i < oldasize; i++) {
            LuaVMTObject* arr = &t->array[i];
            if (arr->tt != LUAVM_TNIL) {
                LuaVMTObject* slot = FUN_00219dc0(t, i + 1);
                if (slot == LUAVM_NILOBJECT) {
                    key.tt = LUAVM_TNUMBER;
                    key.value.n = (float)(i + 1);
                    slot = FUN_0021a3e0(L, t, &key);
                }
                LUAVM_SETOBJ(slot, arr);
            }
        }
        t->array = (LuaVMTObject*)FUN_0021add0(L, t->array, oldasize * (unsigned int)sizeof(LuaVMTObject),
                                               nasize * (unsigned int)sizeof(LuaVMTObject));
    }

    int oldhsize = 1 << oldlsize;
    for (int i = oldhsize - 1; i >= 0; i--) {
        LuaVMNode* old = &nold[i];
        if (old->i_val.tt == LUAVM_TNIL)
            continue;
        LuaVMTObject* k = &old->i_key;
        int ktt = k->tt;
        LuaVMTObject* p = LUAVM_NILOBJECT;
        bool generic = true;
        if (ktt == LUAVM_TNUMBER) {
            float f = k->value.n;
            int ik = (int)f;
            if ((double)ik == (double)f) {
                p = FUN_00219dc0(t, ik);
                generic = false;
            }
        } else if (ktt == LUAVM_TSTRING) {
            LuaVMString* ts = (LuaVMString*)k->value.gc;
            LuaVMNode* n = &t->node[ts->hash & ((1 << t->lsizenode) - 1)];
            do {
                if (n->i_key.tt == LUAVM_TSTRING && (LuaVMString*)n->i_key.value.gc == ts) {
                    p = &n->i_val;
                    break;
                }
                n = n->next;
            } while (n);
            generic = false;
        }
        if (generic && ktt != LUAVM_TNIL) {
            LuaVMNode* n = FUN_002198b0(t, k);
            do {
                if (FUN_00215fa0(&n->i_key, k)) {
                    p = &n->i_val;
                    break;
                }
                n = n->next;
            } while (n);
        }
        t->flags = 0;
        if (p == LUAVM_NILOBJECT) {
            if (k->tt == LUAVM_TNIL) {
                FUN_00214a90(L, "table index is nil");
            } else if (k->tt == LUAVM_TNUMBER && !(k->value.n == k->value.n)) {
                FUN_00214a90(L, "table index is NaN");
            }
            p = FUN_0021a3e0(L, t, k);
        }
        LUAVM_SETOBJ(p, &old->i_val);
    }

    if (oldlsize != 0)
        FUN_0021add0(L, nold, oldhsize * (unsigned int)sizeof(LuaVMNode), 0);
}
