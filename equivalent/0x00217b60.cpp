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
extern "C" int __cdecl FUN_00215fa0(const void *, const void *);

// equiv-conv: FUN_00217b60 edi esi ebx stack
extern "C" void *__cdecl FUN_00217b60(void *mt1, int event, void *mt2, void *L) {
    if (((Table_217b60 *)mt1) == 0 || (((Table_217b60 *)mt1)->flags & (1 << event)) != 0) {
        return (TObject_217b60 *)0;
    }
    TObject_217b60 *tm1 = FUN_00217580(((Table_217b60 *)mt1), event, ((LState_217b60 *)L)->G->tmname[event]);
    if (tm1 == 0) {
        return (TObject_217b60 *)0;
    }
    if (((Table_217b60 *)mt1) == ((Table_217b60 *)mt2)) {
        return (TObject_217b60 *)tm1;
    }
    if (((Table_217b60 *)mt2) == 0 || (((Table_217b60 *)mt2)->flags & (1 << event)) != 0) {
        return (TObject_217b60 *)0;
    }
    TObject_217b60 *tm2 = FUN_00217580(((Table_217b60 *)mt2), event, ((LState_217b60 *)L)->G->tmname[event]);
    if (tm2 == 0) {
        return (TObject_217b60 *)0;
    }
    if (FUN_00215fa0((TObject_217b60 *)tm1, (TObject_217b60 *)tm2)) {
        return (TObject_217b60 *)tm1;
    }
    return (TObject_217b60 *)0;
}
