// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 39/40, incomplete)
// FUN_0003acf0 @ 0x0003acf0
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
#include "decls/address.h"
struct Key {
    int lo;
    int hi;
    Key(const Key &o);
};

struct Matrix {
    float f[16];
    void FUN_0022b980();
};

struct Event_3acf0 {
    char data[0x30];
    Event_3acf0 *FUN_001ca830(Key a, Key b, int c, int d);
    Event_3acf0 *FUN_001ca3d0(Key a, Key b, int c, int d);
};

struct Sink_3acf0 {
    char pad0[0x30];
    void FUN_001cbc20(Event_3acf0 *e);
};

struct World {
    char pad0[0x30];
    Sink_3acf0 *sink;
};

struct CCharacter_3acf0;

struct Obj_3acf0;

struct Owner_3acf0 {
    char pad0[8];
    CCharacter_3acf0 *holder;
    int count;
};

struct Obj_3acf0 {
    virtual void AddRef();
    virtual void Release();
    int pad4;
    Key key;
    char pad10[0xec - 0x10];
    Obj_3acf0 *fec;
    char pad_f0[0x114 - 0xf0];
    Owner_3acf0 *owner;
    void FUN_001d7ee0(int v);
    void FUN_001d71e0(int v);
};

struct Slot_3acf0 {
    Obj_3acf0 *obj;
    int k0;
    int k1;
    int k2;
    Matrix m;
};

struct CCharacter_3acf0 {
    char pad0[0x10];
    int *f10;
    char pad14[0x12c - 0x14];
    int f12c;
    char pad130[0x3a8 - 0x130];
    Slot_3acf0 slots[8];
    char pad628[0x1f51 - 0x628];
    char b1f51;
    Obj_3acf0 *FUN_00035ef0(int i);
    char FUN_0003acf0(int slot, Obj_3acf0 *newObj, int a3, int a4, int a5, Matrix *m);
};


char CCharacter_3acf0::FUN_0003acf0(int slot, Obj_3acf0 *newObj, int a3, int a4, int a5, Matrix *m)
{
    World *g = DAT_004dd700;
    if (slot < 0 || slot >= 8)
        return 0;
    Slot_3acf0 *s = &slots[slot];
    Obj_3acf0 *old = s->obj;
    Event_3acf0 e;
    if (old != 0 && old != newObj) {
        old->FUN_001d7ee0(0);
        old->FUN_001d71e0(0);
        Sink_3acf0 *sink = g->sink;
        if (sink != 0) {
            e.FUN_001ca830(old->key, old->fec->key, *f10, slot);
            sink->FUN_001cbc20(&e);
        }
    }
    if (newObj != 0) {
        Owner_3acf0 *o = newObj->owner;
        if (o != 0 && o->count == 1 && o->holder != 0) {
            CCharacter_3acf0 *h = o->holder;
            for (int j = 0; j < 8; j++) {
                if (h->FUN_00035ef0(j) == newObj && (h != this || j != slot)) {
                    h->FUN_0003acf0(j, 0, -1, 0, 0, 0);
                    break;
                }
            }
        }
        newObj->AddRef();
    }
    if (s->obj != 0)
        s->obj->Release();
    s->obj = newObj;
    s->k0 = a3;
    s->k1 = a4;
    s->k2 = a5;
    if (m != 0)
        s->m = *m;
    else
        s->m.FUN_0022b980();
    if (s->obj != 0)
        s->obj->FUN_001d7ee0(f12c);
    b1f51 = 0;
    if (newObj != 0 && newObj != old) {
        Sink_3acf0 *sink = g->sink;
        if (sink != 0) {
            e.FUN_001ca3d0(newObj->key, newObj->fec->key, *f10, slot);
            sink->FUN_001cbc20(&e);
        }
    }
    return 1;
}
