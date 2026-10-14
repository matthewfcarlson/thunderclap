// STATUS: equivalent (tools/equiv.py level 3: 3005 inputs, branch coverage 14/14)
// FUN_00217b60 @ 0x00217b60
// get_compTM: the comparison metamethod shared by two metatables, or null.
struct TObject_217b60 {
    int tt;
    int value;
};

struct Table_217b60 {
    char pad0[6];
    unsigned char flags;
};

struct GlobalState_217b60 {
    char pad0[0x74];
    void *tmname[1];
};

struct LState_217b60 {
    char pad0[0x10];
    GlobalState_217b60 *G;
};

TObject_217b60 *__cdecl FUN_00217580(Table_217b60 *mt, int event, void *name);
int __cdecl FUN_00215fa0(TObject_217b60 *a, TObject_217b60 *b);

// equiv-conv: FUN_00217b60 edi esi ebx stack
TObject_217b60 *__cdecl FUN_00217b60(Table_217b60 *mt1, int event, Table_217b60 *mt2, LState_217b60 *L) {
    if (mt1 == 0 || (mt1->flags & (1 << event)) != 0) {
        return 0;
    }
    TObject_217b60 *tm1 = FUN_00217580(mt1, event, L->G->tmname[event]);
    if (tm1 == 0) {
        return 0;
    }
    if (mt1 == mt2) {
        return tm1;
    }
    if (mt2 == 0 || (mt2->flags & (1 << event)) != 0) {
        return 0;
    }
    TObject_217b60 *tm2 = FUN_00217580(mt2, event, L->G->tmname[event]);
    if (tm2 == 0) {
        return 0;
    }
    if (FUN_00215fa0(tm1, tm2)) {
        return tm1;
    }
    return 0;
}
