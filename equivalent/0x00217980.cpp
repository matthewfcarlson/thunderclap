// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 24/24)
// FUN_00217980 @ 0x00217980
struct GCObject_217980 {
    char pad0[5];
    unsigned char marked;
};

struct Table_217980;

struct TObject_217980 {
    int tt;
    union {
        void *p;
        GCObject_217980 *gc;
        Table_217980 *h;
    } value;
};

struct Table_217980 {
    char pad0[5];
    unsigned char marked;
    unsigned char flags;
    char pad07;
    Table_217980 *metatable;
};

struct GlobalState_217980 {
    char pad0[0x78];
    void *tmname;
};

struct LState_217980 {
    char pad0[8];
    TObject_217980 *top;
    char pad0c[4];
    GlobalState_217980 *G;
    char pad14[4];
    TObject_217980 *stack_last;
};

TObject_217980 *__cdecl FUN_00219ef0(LState_217980 *L, Table_217980 *h, TObject_217980 *key);
TObject_217980 *__cdecl FUN_00217580(Table_217980 *mt, int event, void *name);
TObject_217980 *__cdecl FUN_002175b0(LState_217980 *L, TObject_217980 *t, int event);
void __cdecl FUN_00217100(LState_217980 *L, Table_217980 *h, GCObject_217980 *v);
void __cdecl FUN_00214c90(LState_217980 *L, TObject_217980 *t, const char *op);
void __cdecl FUN_00214a90(LState_217980 *L, const char *msg);
void __cdecl FUN_00215460(LState_217980 *L, int n);
void __cdecl FUN_002159e0(LState_217980 *L, TObject_217980 *func, int nresults);

void __cdecl FUN_00217980(LState_217980 *L, TObject_217980 *t, TObject_217980 *key, TObject_217980 *val)
{
    for (int loop = 0; loop < 100; loop++) {
        TObject_217980 *tm;
        if (t->tt == 5) {
            Table_217980 *h = t->value.h;
            TObject_217980 *oldval = FUN_00219ef0(L, h, key);
            Table_217980 *mt;
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
            TObject_217980 *func = L->top;
            L->top = func + 4;
            FUN_002159e0(L, func, 0);
            return;
        }
        t = tm;
    }
    FUN_00214a90(L, "loop in settable");
}
