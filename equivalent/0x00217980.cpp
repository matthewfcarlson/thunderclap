// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 24/24)
// FUN_00217980 @ 0x00217980
struct GCObject {
    char pad0[5];
    unsigned char marked;
};

struct Table;

struct TObject {
    int tt;
    union {
        void *p;
        GCObject *gc;
        Table *h;
    } value;
};

struct Table {
    char pad0[5];
    unsigned char marked;
    unsigned char flags;
    char pad07;
    Table *metatable;
};

struct GlobalState {
    char pad0[0x78];
    void *tmname;
};

struct LState {
    char pad0[8];
    TObject *top;
    char pad0c[4];
    GlobalState *G;
    char pad14[4];
    TObject *stack_last;
};

TObject *__cdecl FUN_00219ef0(LState *L, Table *h, TObject *key);
TObject *__cdecl FUN_00217580(Table *mt, int event, void *name);
TObject *__cdecl FUN_002175b0(LState *L, TObject *t, int event);
void __cdecl FUN_00217100(LState *L, Table *h, GCObject *v);
void __cdecl FUN_00214c90(LState *L, TObject *t, const char *op);
void __cdecl FUN_00214a90(LState *L, const char *msg);
void __cdecl FUN_00215460(LState *L, int n);
void __cdecl FUN_002159e0(LState *L, TObject *func, int nresults);

void __cdecl FUN_00217980(LState *L, TObject *t, TObject *key, TObject *val)
{
    for (int loop = 0; loop < 100; loop++) {
        TObject *tm;
        if (t->tt == 5) {
            Table *h = t->value.h;
            TObject *oldval = FUN_00219ef0(L, h, key);
            Table *mt;
            tm = 0;
            if (oldval->tt != 0
                || (mt = h->metatable) == 0
                || (mt->flags & 2) != 0
                || (tm = FUN_00217580(mt, 1, L->G->tmname)) == 0) {
                *oldval = *val;
                if (val->tt >= 4 && (val->value.gc->marked & 3) != 0 && (h->marked & 4) != 0)
                    FUN_00217100(L, h, val->value.gc);
                return;
            }
        } else {
            tm = FUN_002175b0(L, t, 1);
            if (tm->tt == 0)
                FUN_00214c90(L, t, "index");
        }
        if (tm->tt == 6) {
            L->top[0] = *tm;
            L->top[1] = *t;
            L->top[2] = *key;
            L->top[3] = *val;
            if ((char *)L->stack_last - (char *)L->top <= 0x20)
                FUN_00215460(L, 4);
            TObject *func = L->top;
            L->top = func + 4;
            FUN_002159e0(L, func, 0);
            return;
        }
        t = tm;
    }
    FUN_00214a90(L, "loop in settable");
}
