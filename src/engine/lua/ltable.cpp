// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00219870..0x0021a550 (kind game, layer engine, confidence high)
#include "tree_prelude.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/lua.h"
#define TREE_TU_BEGIN namespace fn_fce939df {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fce939df {} using namespace fn_fce939df;
#include "engine/lua.h"

// ---- declarations shared by the functions below
namespace fn_fce939df {
extern "C" void __cdecl FUN_002199d0(int* nums, int ntotal, int* narray, int* nhash);
extern "C" void* __cdecl FUN_0021add0(LuaVMState* L, void* block, unsigned int osize, unsigned int nsize);
extern "C" void __cdecl FUN_00214a90(LuaVMState* L, const char* fmt, ...);
extern "C" void __cdecl FUN_00217130(LuaVMState* L, LuaVMGCObject* o, unsigned char tt);
extern "C" void __cdecl FUN_00219be0(LuaVMTable* t, int size, LuaVMState* L);
extern "C" void __cdecl FUN_00219c30(LuaVMState* L, LuaVMTable* t, int lsize);
extern "C++" __declspec(nothrow) LuaVMNode* __cdecl FUN_002198b0(const LuaVMTable* t, const LuaVMTObject* key);
extern "C" int __cdecl FUN_00215fa0(const LuaVMTObject* t1, const LuaVMTObject* t2);
extern "C" LuaVMTObject* __cdecl FUN_00219dc0(LuaVMTable* t, int key);
extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key);
extern "C" LuaVMTObject* __cdecl FUN_00219d80(const LuaVMTObject* key, LuaVMTable* t);
extern "C" LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key);
extern "C" LuaVMTObject* __cdecl FUN_0021a3e0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key);
extern "C" int __cdecl FUN_00219980(const LuaVMTObject* key, float lim);
extern "C" int __cdecl FUN_00219fb0(const LuaVMTObject* key, LuaVMTable* t, LuaVMState* L);
extern "C" void __cdecl FUN_00219a60(const LuaVMTable* t, int* narray, int* nhash);
extern "C" void __cdecl FUN_0021a0f0(int nasize, LuaVMTable* t, LuaVMState* L, int lsize);
extern "C" void __cdecl FUN_00217100(LuaVMState* L, LuaVMGCObject* o, LuaVMGCObject* v);


// 0x00219870 FUN_00219870 (54 B): equivalent/0x00219870.cpp
// sym: _FUN_00219870
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// hashnum: the main position of a number key (the bits of n + 1 modulo the odd node count).
// equiv-conv: FUN_00219870 esi stack
extern "C" LuaVMNode* __cdecl FUN_00219870(const LuaVMTable* t, float n) {
    unsigned int mask = (1u << (t->lsizenode & 31)) - 1u;
    mask |= 1u;
    union {
        float f;
        unsigned int u;
    } bits;
    bits.f = n + 1.0f;
    return t->node + bits.u % mask;
}

} // namespace fn_fce939df

// 0x002198b0 FUN_002198b0 (185 B): equivalent/0x002198b0.cpp [wrapped: code differs from its standalone build]
// sym: _FUN_002198b0
namespace fn_002198b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3012 inputs, branch coverage 6/6)
// luaH_mainposition: the node a key hashes to (numbers, booleans, strings by their hash, pointers by address).

// equiv-conv: FUN_00219870 esi stack
extern "C++" __declspec(nothrow) LuaVMNode* __cdecl FUN_00219870(const LuaVMTable* t, float n);

extern "C" LuaVMNode* __cdecl FUN_002198b0(const LuaVMTable* t, const LuaVMTObject* key) {
    if (key->tt == LUAVM_TNUMBER)
        return FUN_00219870(t, key->value.n);
    unsigned int mask = (1U << (t->lsizenode & 31)) - 1U;
    unsigned int index;
    switch (key->tt) {
    case LUAVM_TBOOLEAN:
        index = (unsigned int)key->value.b & mask;
        break;
    case LUAVM_TSTRING:
        index = ((const LuaVMString*)key->value.gc)->hash & mask;
        break;
    default:  // the original hashes the 32-bit address
        index = (unsigned int)(hulk_uintptr)key->value.p % (mask | 1U);
        break;
    }
    return t->node + index;
}
} // namespace fn_002198b0

namespace fn_fce939df {

// 0x00219980 FUN_00219980 (79 B): equivalent/0x00219980.cpp
// sym: _FUN_00219980
// STATUS: equivalent (tools/equiv.py level 3: 3007 inputs, branch coverage 8/8)
// arrayindex: a number key's integer value when it is an integer in (0, lim], else -1.
// equiv-conv: FUN_00219980 esi stack
extern "C" int __cdecl FUN_00219980(const LuaVMTObject* key, float lim) {
    if (key->tt == LUAVM_TNUMBER) {
        float n = key->value.n;
        if (n > (*(float*)&DAT_003f32e0) && !(n > lim)) {
            int k = (int)n;
            if (key->value.n == (float)k)
                return k;
        }
    }
    return -1;
}


// 0x002199d0 FUN_002199d0 (134 B): equivalent/0x002199d0.cpp
// sym: _FUN_002199d0
// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 14/14)
// computesizes: the array size (a power of 2 more than half used) for the integer keys counted per power of 2.
// equiv-conv: FUN_002199d0 edx stack stack stack
extern "C" void __cdecl FUN_002199d0(int* nums, int ntotal, int* narray, int* nhash) {
    int a = nums[0];
    int na = a;
    int n = (a != 0) ? 0 : -1;
    int limit = *narray;
    if (a < limit) {
        const int* p = nums + 1;
        int i = 0;
        do {
            int twotoi = 1 << i;
            if (limit < twotoi)
                break;
            int count = *p;
            if (count > 0) {
                a += count;
                if (a >= twotoi) {
                    n = i + 1;
                    na = a;
                }
            }
            p++;
            i++;
        } while (a < *narray);
    }
    *nhash = ntotal - na;
    if (n == -1)
        *narray = 0;
    else
        *narray = 1 << n;
}


// 0x00219a60 FUN_00219a60 (370 B): equivalent/0x00219a60.cpp
// sym: _FUN_00219a60
// STATUS: equivalent (tools/equiv.py level 3: 71 inputs, branch coverage 26/32, incomplete)
// numuse: count a table's used slots and integer keys per power of 2; the array and hash sizes to resize to.
// equiv-conv: FUN_002199d0 edx stack stack stack
extern "C" void __cdecl FUN_00219a60(const LuaVMTable* t, int* narray, int* nhash) {
    int nums[25];
    int totaluse = 0;
    int i = 0;
    int sizearray = t->sizearray;
    int lg = 0;
    for (; lg <= 24; lg++) {
        int lim = 1 << lg;
        if (lim > sizearray) {
            lim = sizearray;
            if (i >= lim)
                break;
        }
        nums[lg] = 0;
        if (i < lim) {
            const LuaVMTObject* p = t->array + i;
            int cnt = lim - i;
            i += cnt;
            do {
                if (p->tt != LUAVM_TNIL) {
                    nums[lg]++;
                    totaluse++;
                }
                p++;
            } while (--cnt != 0);
        }
    }
    for (; lg <= 24; lg++)
        nums[lg] = 0;

    *narray = totaluse;
    int sizenode = 1 << t->lsizenode;
    float limit = (float)(2 * (sizenode + totaluse));
    if (!(limit < 16777216.0f))
        limit = 16777216.0f;
    for (int n = sizenode; n != 0; n--) {
        const LuaVMNode* nd = &t->node[n - 1];
        if (nd->i_val.tt == LUAVM_TNIL)
            continue;
        if (nd->i_key.tt == LUAVM_TNUMBER) {
            float k = nd->i_key.value.n;
            if (!(k <= 0.0f) && !(k > limit)) {
                int ki = (int)k;
                if ((float)ki == k && ki >= 0) {
                    int b = FUN_00215f70((unsigned int)(ki - 1));
                    nums[b + 1] = nums[b + 1] + 1;
                    (*narray)++;
                }
            }
        }
        totaluse++;
    }
    FUN_002199d0(nums, totaluse, narray, nhash);
}


// 0x00219be0 FUN_00219be0 (67 B): equivalent/0x00219be0.cpp
// sym: _FUN_00219be0
// STATUS: equivalent (tools/equiv.py level 3: 2694 inputs, branch coverage 4/4)
// setarrayvector: resize a table's array part to size slots (the new ones nil).
// equiv-conv: FUN_00219be0 esi edi stack
extern "C" void __cdecl FUN_00219be0(LuaVMTable* t, int size, LuaVMState* L) {
    t->array = (LuaVMTObject*)FUN_0021add0(L, t->array, t->sizearray * (unsigned int)sizeof(LuaVMTObject),
                                           size * (unsigned int)sizeof(LuaVMTObject));
    for (int i = t->sizearray; i < size; ++i)
        t->array[i].tt = LUAVM_TNIL;
    t->sizearray = size;
}


// 0x00219c30 FUN_00219c30 (131 B): equivalent/0x00219c30.cpp
// sym: _FUN_00219c30
// STATUS: equivalent (tools/equiv.py level 3: 115 inputs, branch coverage 8/8)
// setnodevector: a table's hash part of 2^lsize empty nodes (the global dummy node for 0).
// equiv-conv: FUN_00219c30 ebx esi stack
extern "C" void __cdecl FUN_00219c30(LuaVMState* L, LuaVMTable* t, int lsize) {
    int size = 1 << lsize;

    if (lsize > 24)
        FUN_00214a90(L, "table overflow");

    if (lsize == 0) {
        t->node = L->l_G->dummynode;
    } else {
        t->node = (LuaVMNode*)FUN_0021add0(L, 0, 0, size * (unsigned int)sizeof(LuaVMNode));
        for (int i = 0; i < size; i++) {
            t->node[i].next = 0;
            t->node[i].i_key.tt = LUAVM_TNIL;
            t->node[i].i_val.tt = LUAVM_TNIL;
        }
    }
    t->lsizenode = (unsigned char)lsize;
    t->firstfree = &t->node[size - 1];
}


// 0x00219cc0 FUN_00219cc0 (82 B): equivalent/0x00219cc0.cpp
// sym: _FUN_00219cc0
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 0/0)
// luaH_new: a table with narray array slots and 2^lnhash nodes.
// equiv-conv: FUN_00219be0 esi edi stack
// equiv-conv: FUN_00219c30 ebx esi stack
extern "C" LuaVMTable* __cdecl FUN_00219cc0(LuaVMState* L, int narray, int lnhash) {
    LuaVMTable* t = (LuaVMTable*)FUN_0021add0(L, 0, 0, sizeof(LuaVMTable));
    FUN_00217130(L, (LuaVMGCObject*)t, LUAVM_TTABLE);
    t->metatable = 0;
    t->flags = 0xff;
    t->array = 0;
    t->sizearray = 0;
    t->lsizenode = 0;
    t->node = 0;
    FUN_00219be0(t, narray, L);
    FUN_00219c30(L, t, lnhash);
    return t;
}


// 0x00219d20 FUN_00219d20 (82 B): matches/0x00219d20.cpp
// sym: _FUN_00219d20
// luaH_free: free a table's hash part (unless it is the dummy node), its array part and the table.
extern "C" void __cdecl FUN_00219d20(LuaVMState* L, LuaVMTable* t) {
    if (t->lsizenode)
        FUN_0021add0(L, t->node, (1 << t->lsizenode) * (unsigned int)sizeof(LuaVMNode), 0);
    FUN_0021add0(L, t->array, t->sizearray * (unsigned int)sizeof(LuaVMTObject), 0);
    FUN_0021add0(L, t, sizeof(LuaVMTable), 0);
}


// 0x00219d80 FUN_00219d80 (55 B): equivalent/0x00219d80.cpp
// sym: _FUN_00219d80
// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 6/6)
// luaH_getany: the value under a key of any type (by raw equality along its chain), or luaO_nilobject.
// equiv-conv: FUN_00219d80 edi stack
extern "C" LuaVMTObject* __cdecl FUN_00219d80(const LuaVMTObject* key, LuaVMTable* t) {
    if (key->tt != LUAVM_TNIL) {
        LuaVMNode* n = FUN_002198b0(t, key);
        do {
            if (FUN_00215fa0(&n->i_key, key) != 0)
                return &n->i_val;
            n = n->next;
        } while (n != 0);
    }
    return LUAVM_NILOBJECT;
}


// 0x00219dc0 FUN_00219dc0 (131 B): equivalent/0x00219dc0.cpp
// sym: _FUN_00219dc0
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 10/10)
// luaH_getnum: the value under an integer key (the array part, else the hash part), or luaO_nilobject.
extern "C" LuaVMTObject* __cdecl FUN_00219dc0(LuaVMTable* t, int key) {
    if (1 <= key && key <= t->sizearray)
        return &t->array[key - 1];

    float nk = (float)key;
    union {
        float f;
        unsigned int bits;
    } h;
    h.f = nk + 1.0f;
    unsigned int mod = ((1u << t->lsizenode) - 1) | 1;
    LuaVMNode* n = &t->node[h.bits % mod];
    do {
        if (n->i_key.tt == LUAVM_TNUMBER && n->i_key.value.n == nk)
            return &n->i_val;
        n = n->next;
    } while (n != 0);
    return LUAVM_NILOBJECT;
}


// 0x00219e50 FUN_00219e50 (62 B): matches/0x00219e50.cpp
// sym: _FUN_00219e50
// luaH_getstr: the value under a string key, or luaO_nilobject.
extern "C" LuaVMTObject* __cdecl FUN_00219e50(LuaVMTable* t, LuaVMString* key) {
    unsigned int size = 1u << t->lsizenode;
    LuaVMNode* n = t->node + ((size - 1) & key->hash);
    while (n->i_key.tt != LUAVM_TSTRING || (LuaVMString*)n->i_key.value.gc != key) {
        n = n->next;
        if (!n)
            return LUAVM_NILOBJECT;
    }
    return &n->i_val;
}


// 0x00219e90 FUN_00219e90 (83 B): equivalent/0x00219e90.cpp
// sym: _FUN_00219e90
// STATUS: equivalent (tools/equiv.py level 3: 3004 inputs, branch coverage 6/6)
// luaH_get: the value under a key (integers and strings by their fast paths), or luaO_nilobject.
// equiv-conv: FUN_00219d80 edi stack
extern "C" LuaVMTObject* __cdecl FUN_00219e90(LuaVMTable* t, const LuaVMTObject* key) {
    if (key->tt == LUAVM_TNUMBER) {
        int k = (int)key->value.n;
        if (key->value.n == (float)k)
            return FUN_00219dc0(t, k);
    } else if (key->tt == LUAVM_TSTRING) {
        return FUN_00219e50(t, (LuaVMString*)key->value.gc);
    }
    return FUN_00219d80(key, t);
}


// 0x00219ef0 FUN_00219ef0 (99 B): matches/0x00219ef0.cpp
// sym: _FUN_00219ef0
// luaH_set: the slot for key, made by newkey when absent (a nil or NaN key is an error); clears the metamethod cache.
extern "C" LuaVMTObject* __cdecl FUN_00219ef0(LuaVMState* L, LuaVMTable* t, const LuaVMTObject* key) {
    LuaVMTObject* p = FUN_00219e90(t, key);
    t->flags = 0;
    if (p == LUAVM_NILOBJECT) {
        if (key->tt == LUAVM_TNIL) {
            FUN_00214a90(L, "table index is nil");
        } else if (key->tt == LUAVM_TNUMBER) {
            float x = key->value.n;
            if (x != x)
                FUN_00214a90(L, "table index is NaN");
        }
        return FUN_0021a3e0(L, t, key);
    }
    return p;
}


// 0x00219f60 FUN_00219f60 (69 B): matches/0x00219f60.cpp
// sym: _FUN_00219f60
// luaH_setnum: the slot for an integer key, made by newkey when absent.
extern "C" LuaVMTObject* __cdecl FUN_00219f60(LuaVMState* L, LuaVMTable* t, int key) {
    LuaVMTObject k;
    LuaVMTObject* p = FUN_00219dc0(t, key);
    if (p == LUAVM_NILOBJECT) {
        k.value.n = (float)key;
        k.tt = LUAVM_TNUMBER;
        return FUN_0021a3e0(L, t, &k);
    }
    return p;
}


// 0x00219fb0 FUN_00219fb0 (98 B): equivalent/0x00219fb0.cpp
// sym: _FUN_00219fb0
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 6/6)
// luaH_index: the traversal index of a key for next (-1 for nil; array slots first, then the nodes).
// equiv-conv: FUN_00219980 esi stack
// equiv-conv: FUN_00219fb0 eax edi stack
extern "C" int __cdecl FUN_00219fb0(const LuaVMTObject* key, LuaVMTable* t, LuaVMState* L) {
    if (key->tt == LUAVM_TNIL)
        return -1;
    int i = FUN_00219980(key, (float)t->sizearray);
    if (i >= 0)
        return i - 1;
    const LuaVMTObject* v = FUN_00219e90(t, key);
    if (v == LUAVM_NILOBJECT)
        FUN_00214a90(L, "invalid key for `next'");
    return (int)(((const char*)v - (const char*)&t->node[0].i_val) / sizeof(LuaVMNode)) + t->sizearray;
}


// 0x0021a020 FUN_0021a020 (193 B): equivalent/0x0021a020.cpp
// sym: _FUN_0021a020
// STATUS: equivalent (tools/equiv.py level 3: 1449 inputs, branch coverage 12/12)
// luaH_next: the key and value after key (in key[0], key[1]); 0 at the end.
// equiv-conv: FUN_00219fb0 eax edi stack
extern "C" int __cdecl FUN_0021a020(LuaVMState* L, LuaVMTable* t, LuaVMTObject* key) {
    int i = FUN_00219fb0(key, t, L) + 1;
    int sizearray = t->sizearray;
    if (i < sizearray) {
        LuaVMTObject* slot = t->array + i;
        while (i < sizearray) {
            if (slot->tt != LUAVM_TNIL) {
                key[0].tt = LUAVM_TNUMBER;
                key[0].value.n = (float)(i + 1);
                LUAVM_SETOBJ(key + 1, &t->array[i]);
                return 1;
            }
            ++i;
            ++slot;
        }
    }
    i -= sizearray;
    int sizenode = (int)(1u << (t->lsizenode & 31));
    if (i < sizenode) {
        LuaVMNode* n = t->node + i;
        while (i < sizenode) {
            if (n->i_val.tt != LUAVM_TNIL) {
                LUAVM_SETOBJ(key, &n->i_key);
                LUAVM_SETOBJ(key + 1, &t->node[i].i_val);
                return 1;
            }
            ++i;
            ++n;
        }
    }
    return 0;
}


// 0x0021a0f0 FUN_0021a0f0 (675 B): equivalent/0x0021a0f0.cpp
// sym: _FUN_0021a0f0
// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 25/46, incomplete)
// resize: give a table nasize array slots and 2^lsize nodes, re-inserting the values that moved.
// equiv-conv: FUN_00219be0 esi edi stack
// equiv-conv: FUN_00219c30 ebx esi stack
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


// 0x0021a3a0 FUN_0021a3a0 (50 B): equivalent/0x0021a3a0.cpp
// sym: _FUN_0021a3a0
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// rehash: resize a table to the sizes its use asks for.
// equiv-conv: FUN_0021a0f0 eax ecx stack stack
// equiv-conv: FUN_0021a3a0 esi stack
extern "C" void __cdecl FUN_0021a3a0(LuaVMTable* t, LuaVMState* L) {
    int nhsize;
    int nasize;
    FUN_00219a60(t, &nasize, &nhsize);
    int lsize = FUN_00215f70((unsigned int)nhsize);
    FUN_0021a0f0(nasize, t, L, lsize + 1);
}


// 0x0021a3e0 FUN_0021a3e0 (277 B): equivalent/0x0021a3e0.cpp
// sym: _FUN_0021a3e0
// STATUS: equivalent (tools/equiv.py level 3: 441 inputs, branch coverage 20/20)
// newkey: insert a key into its main position (moving a colliding node that is not in its own main position to
// a free node), with the barrier; when no free node is left, rehash and look the key up again.
// equiv-conv: FUN_0021a0f0 eax ecx stack stack
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


// 0x0021a500 FUN_0021a500 (67 B): matches/0x0021a500.cpp
// sym: _FUN_0021a500
// luaH_setstr: the slot for a string key, made by newkey when absent.
extern "C" LuaVMTObject* __cdecl FUN_0021a500(LuaVMState* L, LuaVMTable* t, LuaVMString* key) {
    LuaVMTObject k;
    LuaVMTObject* p = FUN_00219e50(t, key);
    if (p == LUAVM_NILOBJECT) {
        k.value.gc = (LuaVMGCObject*)key;
        k.tt = LUAVM_TSTRING;
        return FUN_0021a3e0(L, t, &k);
    }
    return p;
}

} // namespace fn_fce939df
