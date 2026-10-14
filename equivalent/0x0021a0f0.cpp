// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 44/46, incomplete)
// FUN_0021a0f0 @ 0x0021a0f0
union Value_21a0f0 {
    float n;
    void *p;
    int i;
};

struct TValue_21a0f0 {
    int tt;
    Value_21a0f0 value;
};

struct Node {
    TValue_21a0f0 key;
    TValue_21a0f0 val;
    Node *next;
};

struct TString_21a0f0 {
    char pad0[8];
    unsigned int hash;
};

struct Global_21a0f0 {
    char pad0[0x60];
    Node dummynode;             // 0x60
};

struct lua_State_21a0f0 {
    char pad0[0x10];
    Global_21a0f0 *g;                  // 0x10
};

struct Table_21a0f0 {
    char pad0[6];
    unsigned char flags;        // 0x6
    unsigned char lsizenode;    // 0x7
    char pad8[4];
    TValue_21a0f0 *array;              // 0xc
    Node *node;                 // 0x10
    char pad14[8];
    int sizearray;              // 0x1c
};

extern TValue_21a0f0 DAT_00426824;     // nil object

// equiv-conv: FUN_00219be0 esi edi stack
void FUN_00219be0(Table_21a0f0 *t, int nasize, lua_State_21a0f0 *L);
// equiv-conv: FUN_00219c30 ebx esi stack
void FUN_00219c30(lua_State_21a0f0 *L, Table_21a0f0 *t, int lsize);
TValue_21a0f0 *__cdecl FUN_00219dc0(Table_21a0f0 *t, int n);
TValue_21a0f0 *__cdecl FUN_0021a3e0(lua_State_21a0f0 *L, Table_21a0f0 *t, TValue_21a0f0 *key);
void *__cdecl FUN_0021add0(lua_State_21a0f0 *L, void *block, unsigned int oldsize, unsigned int newsize);
Node *__cdecl FUN_002198b0(Table_21a0f0 *t, TValue_21a0f0 *key);
int __cdecl FUN_00215fa0(Node *n, TValue_21a0f0 *key);
void __cdecl FUN_00214a90(lua_State_21a0f0 *L, const char *msg);

// Lua 5.0 luaH_resize: nasize arrives in eax, the table in ecx.
// equiv-conv: FUN_0021a0f0 eax ecx stack stack
void FUN_0021a0f0(int nasize, Table_21a0f0 *t, lua_State_21a0f0 *L, int lsize)
{
    int oldasize = t->sizearray;
    int oldlsize = t->lsizenode;
    Node *nold;
    Node dummy;
    TValue_21a0f0 key;

    if (oldlsize == 0) {
        dummy = *t->node;
        L->g->dummynode.key.tt = 0;
        nold = &dummy;
        L->g->dummynode.val.tt = 0;
    } else {
        nold = t->node;
    }

    if (nasize > oldasize)
        FUN_00219be0(t, nasize, L);
    FUN_00219c30(L, t, lsize);

    if (nasize < oldasize) {
        t->sizearray = nasize;
        for (int i = nasize; i < oldasize; i++) {
            TValue_21a0f0 *arr = &t->array[i];
            if (arr->tt != 0) {
                TValue_21a0f0 *slot = FUN_00219dc0(t, i + 1);
                if (slot == &DAT_00426824) {
                    key.tt = 3;
                    key.value.n = (float)(i + 1);
                    slot = FUN_0021a3e0(L, t, &key);
                }
                slot->tt = arr->tt;
                slot->value = arr->value;
            }
        }
        t->array = (TValue_21a0f0 *)FUN_0021add0(L, t->array, oldasize * 8, nasize * 8);
    }

    int oldhsize = 1 << oldlsize;
    for (int i = oldhsize - 1; i >= 0; i--) {
        Node *old = &nold[i];
        if (old->val.tt == 0)
            continue;
        TValue_21a0f0 *k = &old->key;
        int ktt = k->tt;
        TValue_21a0f0 *p = &DAT_00426824;
        bool generic = true;
        if (ktt == 3) {
            float f = k->value.n;
            int ik = (int)f;
            if ((double)ik == (double)f) {
                p = FUN_00219dc0(t, ik);
                generic = false;
            }
        } else if (ktt == 4) {
            TString_21a0f0 *ts = (TString_21a0f0 *)k->value.p;
            Node *n = &t->node[ts->hash & ((1 << t->lsizenode) - 1)];
            do {
                if (n->key.tt == 4 && n->key.value.p == ts) {
                    p = &n->val;
                    break;
                }
                n = n->next;
            } while (n);
            generic = false;
        }
        if (generic && ktt != 0) {
            Node *n = FUN_002198b0(t, k);
            do {
                if (FUN_00215fa0(n, k)) {
                    p = &n->val;
                    break;
                }
                n = n->next;
            } while (n);
        }
        t->flags = 0;
        if (p == &DAT_00426824) {
            if (k->tt == 0) {
                FUN_00214a90(L, "table index is nil");
            } else if (k->tt == 3 && !(k->value.n == k->value.n)) {
                FUN_00214a90(L, "table index is NaN");
            }
            p = FUN_0021a3e0(L, t, k);
        }
        p->tt = old->val.tt;
        p->value = old->val.value;
    }

    if (oldlsize != 0)
        FUN_0021add0(L, nold, oldhsize * 20, 0);
}
