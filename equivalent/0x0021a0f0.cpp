// STATUS: equivalent (tools/equiv.py level 3: 92 inputs, branch coverage 44/46, incomplete)
// FUN_0021a0f0 @ 0x0021a0f0
union Value {
    float n;
    void *p;
    int i;
};

struct TValue {
    int tt;
    Value value;
};

struct Node {
    TValue key;
    TValue val;
    Node *next;
};

struct TString {
    char pad0[8];
    unsigned int hash;
};

struct Global {
    char pad0[0x60];
    Node dummynode;             // 0x60
};

struct lua_State {
    char pad0[0x10];
    Global *g;                  // 0x10
};

struct Table {
    char pad0[6];
    unsigned char flags;        // 0x6
    unsigned char lsizenode;    // 0x7
    char pad8[4];
    TValue *array;              // 0xc
    Node *node;                 // 0x10
    char pad14[8];
    int sizearray;              // 0x1c
};

extern TValue DAT_00426824;     // nil object

// equiv-conv: FUN_00219be0 esi edi stack
void FUN_00219be0(Table *t, int nasize, lua_State *L);
// equiv-conv: FUN_00219c30 ebx esi stack
void FUN_00219c30(lua_State *L, Table *t, int lsize);
TValue *__cdecl FUN_00219dc0(Table *t, int n);
TValue *__cdecl FUN_0021a3e0(lua_State *L, Table *t, TValue *key);
void *__cdecl FUN_0021add0(lua_State *L, void *block, unsigned int oldsize, unsigned int newsize);
Node *__cdecl FUN_002198b0(Table *t, TValue *key);
int __cdecl FUN_00215fa0(Node *n, TValue *key);
void __cdecl FUN_00214a90(lua_State *L, const char *msg);

// Lua 5.0 luaH_resize: nasize arrives in eax, the table in ecx.
// equiv-conv: FUN_0021a0f0 eax ecx stack stack
void FUN_0021a0f0(int nasize, Table *t, lua_State *L, int lsize)
{
    int oldasize = t->sizearray;
    int oldlsize = t->lsizenode;
    Node *nold;
    Node dummy;
    TValue key;

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
            TValue *arr = &t->array[i];
            if (arr->tt != 0) {
                TValue *slot = FUN_00219dc0(t, i + 1);
                if (slot == &DAT_00426824) {
                    key.tt = 3;
                    key.value.n = (float)(i + 1);
                    slot = FUN_0021a3e0(L, t, &key);
                }
                slot->tt = arr->tt;
                slot->value = arr->value;
            }
        }
        t->array = (TValue *)FUN_0021add0(L, t->array, oldasize * 8, nasize * 8);
    }

    int oldhsize = 1 << oldlsize;
    for (int i = oldhsize - 1; i >= 0; i--) {
        Node *old = &nold[i];
        if (old->val.tt == 0)
            continue;
        TValue *k = &old->key;
        int ktt = k->tt;
        TValue *p = &DAT_00426824;
        bool generic = true;
        if (ktt == 3) {
            float f = k->value.n;
            int ik = (int)f;
            if ((double)ik == (double)f) {
                p = FUN_00219dc0(t, ik);
                generic = false;
            }
        } else if (ktt == 4) {
            TString *ts = (TString *)k->value.p;
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
