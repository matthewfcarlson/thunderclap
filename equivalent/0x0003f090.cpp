// STATUS: equivalent (tools/equiv.py level 3: 504 inputs, branch coverage 53/54, incomplete)
// FUN_0003f090 @ 0x0003f090
// equiv-map: ?FUN_00232240@SubObj@@QAEXXZ = 0x002325f0
inline void *operator new(unsigned int, void *p) throw() { return p; }

class Releasable {
public:
    virtual void v0();
    virtual void release();
};

class Wide {
public:
    virtual void v0();
    virtual void release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

struct Id64 {
    unsigned int lo, hi;
    void FUN_0027af10(unsigned int lo, unsigned int hi);
    void FUN_0027af50() throw();
};

struct Id16 {
    Id64 id;
    char pad8[8];
    void FUN_0027af50() throw();
};

struct Pair2 {
    char pad0[8];
    int f8;
    int fc;
    char pad10[0x148 - 0x10];
    int f148;
};

struct Linked {
    virtual void v0();
    virtual void release();
    char pad4[4];
    int f8;
    int fc;
};

struct Linked2 {
    virtual void v0();
    virtual void release();
    char pad4[0x144];
    int f148;
};

struct SlotOwner {
    void FUN_001e5bb0(Releasable *r, int flag);
};

struct World {
    char padx[0xc];
    SlotOwner *f0c;
};
extern World *DAT_004dd700;

struct Handle {
    void FUN_001c3b30(Id64 *id);
};
Handle *FUN_001c3d90();

struct Registry {
    void FUN_001b4140(void *owner);
};
Registry *FUN_001b6580();

struct Slot {
    Releasable *a;
    Releasable *b;
    char pad8[0x28 - 8];
};

struct Item50 {
    Releasable *obj;
    char pad4[0x4c];
};

struct SubObj {
    char data[0x28];
    void FUN_00232240() throw();
};

class CCharacter {
public:
    virtual void v0();
    virtual void v1();
    char pad04[4];
    unsigned int f08;
    unsigned int f0c;
    char pad10[0xb4 - 0x10];
    SubObj sub_b4;
    SubObj sub_dc;
    Releasable *f104;
    Releasable *f108;
    Releasable *f10c;
    char pad110[0x11c - 0x110];
    Releasable *f11c;
    Releasable *f120;
    int f124;
    Linked2 *f128;
    Linked *f12c;
    Releasable *f130;
    char pad134[0x14c - 0x134];
    Releasable *f14c;
    char pad150[0x328 - 0x150];
    Releasable *f328;
    char pad32c[0x388 - 0x32c];
    Releasable *f388;
    char pad38c[0x3a4 - 0x38c];
    Releasable *f3a4;
    Item50 items[8];
    char pad628[0x638 - 0x628];
    Slot slots[0x80];
    char pad1a38[0x1ad0 - 0x1a38];
    Releasable *f1ad0;
    char pad1ad4[0x1b50 - 0x1ad4];
    Id64 id1b50;
    char pad1b58[0x1b98 - 0x1b58];
    Id64 id1b98;
    char pad1ba0[0x1ba8 - 0x1ba0];
    Id16 ids1ba8[14];
    char pad1c88[0x1c98 - 0x1c88];
    Id64 id1c98;
    Wide *f1ca0;
    Releasable *f1ca4;
    char pad1ca8[0x1d68 - 0x1ca8];
    Id64 id1d68;
    Id64 id1d70;
    char pad1d78[0x2098 - 0x1d78];
    Id64 id2098;
    char pad20a0[0x2150 - 0x20a0];
    Id16 ids2150[16];
    char pad2250[0x2258 - 0x2250];
    Id16 ids2250[4];
    char pad2298[0x22b4 - 0x2298];
    Releasable *f22b4;
    Id64 id22b8;
    char pad22c0[0x22e4 - 0x22c0];
    Releasable *f22e4;

    void FUN_0003b620(int v);
    void FUN_0003acf0(int a, int b, int c, int d, int e, int f);
    void FUN_000393c0();
    void FUN_0027afd0();
    void FUN_0003f090();
};

void CCharacter::FUN_0003f090()
{
    new (this) CCharacter;
    World *w = DAT_004dd700;
    FUN_0003b620(0);
    if (f22e4) {
        f22e4->release();
        f22e4 = 0;
    }
    f1ca0->v7();
    f1ca0->release();
    if (f1ad0) {
        f1ad0->release();
        f1ad0 = 0;
    }
    SlotOwner *owner = w->f0c;
    for (int i = 0; i < 8; i++) {
        Releasable *r = items[i].obj;
        if (r) {
            r->v0();
            FUN_0003acf0(i, 0, -1, 0, 0, 0);
            owner->FUN_001e5bb0(r, 1);
            r->release();
        }
    }
    if (f3a4) {
        f3a4->release();
        f3a4 = 0;
    }
    if (f22b4) {
        f22b4->release();
        f22b4 = 0;
    }
    if (f388) {
        f388->release();
        f388 = 0;
    }
    FUN_000393c0();
    if (f328) {
        f328->release();
        f328 = 0;
    }
    if (f14c) {
        f14c->release();
        f14c = 0;
    }
    FUN_001b6580()->FUN_001b4140(this);
    if (f130) {
        f130->release();
        f130 = 0;
    }
    if (f12c) {
        f12c->fc = 0;
        f12c->f8 = 0;
        if (f12c) {
            f12c->release();
            f12c = 0;
        }
    }
    if (f128) {
        f128->f148 = 0;
        owner->FUN_001e5bb0((Releasable *)f128, 1);
    }
    if (f128) {
        f128->release();
        f128 = 0;
    }
    if (f124) {
        Id64 key;
        key.FUN_0027af10(f08, f0c);
        FUN_001c3d90()->FUN_001c3b30(&key);
        key.FUN_0027af50();
    }
    if (f120) {
        f120->release();
        f120 = 0;
    }
    if (f11c) {
        f11c->release();
        f11c = 0;
    }
    if (f108) {
        f108->release();
        f108 = 0;
    }
    if (f10c) {
        f10c->release();
        f10c = 0;
    }
    if (f104) {
        f104->release();
        f104 = 0;
    }
    if (f1ca4) {
        f1ca4->release();
        f1ca4 = 0;
    }

    id22b8.FUN_0027af50();
    int i;
    for (i = 3; i >= 0; i--)
        ids2250[i].FUN_0027af50();
    for (i = 15; i >= 0; i--)
        ids2150[i].FUN_0027af50();
    id2098.FUN_0027af50();
    id1d70.FUN_0027af50();
    id1d68.FUN_0027af50();
    id1c98.FUN_0027af50();
    for (i = 13; i >= 0; i--)
        ids1ba8[i].FUN_0027af50();
    id1b98.FUN_0027af50();
    id1b50.FUN_0027af50();
    for (i = 0x7f; i >= 0; i--) {
        if (slots[i].b) {
            slots[i].b->release();
            slots[i].b = 0;
        }
        if (slots[i].a) {
            slots[i].a->release();
            slots[i].a = 0;
        }
    }
    sub_dc.FUN_00232240();
    sub_b4.FUN_00232240();
    FUN_0027afd0();
}
