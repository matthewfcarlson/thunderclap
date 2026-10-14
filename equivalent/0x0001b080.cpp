// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0001b080 @ 0x0001b080
// FUN_0001b080: CWeaponCollisionAction constructor
struct RefObj_1b080 {
    virtual void AddRef();
    virtual void Release();
};

struct V3i {
    int x, y, z;
};

struct Owner_1b080 {
    char pad00[0xb8];
    V3i pos;
};

extern "C" char DAT_003f3390[];
extern "C" char DAT_003f34c8[];

struct CWeaponCollisionAction {
    int vptr;
    char pad04[0x18];
    RefObj_1b080 *f1c;
    Owner_1b080 *owner;
    int f24;
    char b28;
    char pad29[3];
    int f2c;
    int f30;
    char pad34[0x40];
    int f74;
    int f78;
    RefObj_1b080 *f7c;

    void FUN_00232660();
    CWeaponCollisionAction *FUN_0001b080(RefObj_1b080 *a, Owner_1b080 *b, RefObj_1b080 *c);
};

CWeaponCollisionAction *CWeaponCollisionAction::FUN_0001b080(RefObj_1b080 *a, Owner_1b080 *b, RefObj_1b080 *c)
{
    FUN_00232660();
    vptr = (int)DAT_003f3390;
    f1c = 0;
    if (c)
        c->AddRef();
    if (f1c)
        f1c->Release();
    f1c = c;
    owner = b;
    vptr = (int)DAT_003f34c8;
    f24 = 0;
    b28 = 0;
    f2c = 0;
    f30 = 0;
    f7c = 0;
    V3i p = b->pos;
    f74 = p.y;
    f78 = p.z;
    if (a)
        a->AddRef();
    if (f7c)
        f7c->Release();
    f7c = a;
    return this;
}
