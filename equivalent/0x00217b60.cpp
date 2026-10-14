// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 14/14)
// FUN_00217b60 @ 0x00217b60
// get_compTM: the comparison metamethod shared by two metatables, or null.
struct TObject {
    int tt;
    int value;
};

struct Table {
    char pad0[6];
    unsigned char flags;
};

struct GlobalState {
    char pad0[0x74];
    void *tmname[1];
};

struct LState {
    char pad0[0x10];
    GlobalState *G;
};

TObject *__cdecl FUN_00217580(Table *mt, int event, void *name);
int __cdecl FUN_00215fa0(TObject *a, TObject *b);

// equiv-conv: FUN_00217b60 edi esi ebx stack
TObject *__cdecl FUN_00217b60(Table *mt1, int event, Table *mt2, LState *L) {
    if (mt1 == 0 || (mt1->flags & (1 << event)) != 0) {
        return 0;
    }
    TObject *tm1 = FUN_00217580(mt1, event, L->G->tmname[event]);
    if (tm1 == 0) {
        return 0;
    }
    if (mt1 == mt2) {
        return tm1;
    }
    if (mt2 == 0 || (mt2->flags & (1 << event)) != 0) {
        return 0;
    }
    TObject *tm2 = FUN_00217580(mt2, event, L->G->tmname[event]);
    if (tm2 == 0) {
        return 0;
    }
    if (FUN_00215fa0(tm1, tm2)) {
        return tm1;
    }
    return 0;
}
