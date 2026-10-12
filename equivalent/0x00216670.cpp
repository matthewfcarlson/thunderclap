// STATUS: equivalent (tools/equiv.py level 3: 53 inputs, branch coverage 44/54, incomplete)
// FUN_00216670 @ 0x00216670
extern "C" char *__cdecl strchr(const char *s, int c);

struct GCHeader {
    void *next;              // 0x00
    unsigned char tt;        // 0x04
    unsigned char marked;    // 0x05
    unsigned char flags;     // 0x06
    unsigned char lsizenode; // 0x07
};

struct TString : GCHeader {
    char pad08[8];
    char str[1];             // 0x10
};

struct TValue {
    int tt;
    GCHeader *value;
};

struct Node {
    TValue key;
    TValue val;
    Node *next;
};

struct Table : GCHeader {
    Table *metatable;        // 0x08
    TValue *array;           // 0x0c
    Node *node;              // 0x10
    Node *lastfree;          // 0x14
    GCHeader *gclist;        // 0x18
    int sizearray;           // 0x1c
};

struct GlobalState {
    char pad00[0x30];
    Table *gray;             // 0x30
    char pad34[0x80 - 0x34];
    void *tmname;            // 0x80
};

void __cdecl FUN_002164b0(GlobalState *g, GCHeader *o);
TValue *__cdecl FUN_00217580(Table *mt, int event, void *name);

// equiv-conv: FUN_00216670 edi stack
int FUN_00216670(Table *t, GlobalState *g)
{
    int weakkey = 0;
    int weakvalue = 0;

    if (t->metatable && (t->metatable->marked & 3))
        FUN_002164b0(g, t->metatable);

    Table *mt = t->metatable;
    if (mt && !(mt->flags & 8)) {
        TValue *mode = FUN_00217580(mt, 3, g->tmname);
        if (mode && mode->tt == 4) {
            weakkey = strchr(static_cast<TString *>(mode->value)->str, 'k') != 0;
            weakvalue = strchr(static_cast<TString *>(mode->value)->str, 'v') != 0;
            if (weakkey || weakvalue) {
                t->marked = (t->marked & 0xe7) | (((weakvalue << 1) | weakkey) << 3);
                t->gclist = g->gray;
                g->gray = t;
            }
            if (weakkey && weakvalue)
                return 1;
        }
    }

    if (!weakvalue) {
        int i = t->sizearray;
        while (i != 0) {
            i--;
            TValue *v = &t->array[i];
            if (v->tt >= 4 && (v->value->marked & 3))
                FUN_002164b0(g, v->value);
        }
    }

    int n = 1 << t->lsizenode;
    while (n != 0) {
        n--;
        Node *nd = &t->node[n];
        if (nd->val.tt == 0) {
            int keytt = nd->key.tt;
            nd->val.tt = 0;
            if (keytt >= 4)
                nd->key.tt = -1;
        } else {
            if (!weakkey && nd->key.tt >= 4 && (nd->key.value->marked & 3))
                FUN_002164b0(g, nd->key.value);
            if (!weakvalue && nd->val.tt >= 4 && (nd->val.value->marked & 3))
                FUN_002164b0(g, nd->val.value);
        }
    }
    return weakkey || weakvalue;
}
