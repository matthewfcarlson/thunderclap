// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 32/32)
// FUN_001da350 @ 0x001da350
class RefCounted {
public:
    virtual void addRef();
    virtual void release();
};

struct Raw3 {
    unsigned a, b, c;
};

struct Xform {
    char pad[0x30];
    Raw3 pos;
};

class PosSource {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Raw3 *getPos();
};

struct Inner70 {
    void FUN_002f5a20(Raw3 *p);
};

struct Mid10 {
    char pad[0x70];
    Inner70 *p70;
};

struct HolderA0 {
    char pad[0x10];
    Mid10 *p10;
    Xform *FUN_002fc6f0();
};

struct Reg124 {
    char pad[0x12c];
    RefCounted *key;
};

struct Reg20 {
    char pad[0x124];
    Reg124 *p124;
    void FUN_00029b50(unsigned a, unsigned b, unsigned c);
};

struct Globals {
    char pad[0x20];
    Reg20 *p20;
};

extern Globals *DAT_004dd700;

struct Sub240 {
    char pad[8];
    void FUN_0027af70(unsigned a);
};

struct Ready {
    char FUN_001d4ef0();
};

class Entity {
public:
    char pad00[0xa0];
    HolderA0 *holder;        // 0xa0
    char pada4[0xec - 0xa4];
    Ready *ready;            // 0xec
    char padf0[0x114 - 0xf0];
    int f114;
    char pad118[4];
    PosSource *posSource;    // 0x11c
    char pad120[0x188 - 0x120];
    Raw3 pos;                // 0x188
    char pad194[0x1fc - 0x194];
    RefCounted *rc1fc;
    Raw3 v200;
    Raw3 v20c;
    unsigned f218;
    RefCounted *rc21c;
    Raw3 v220;
    Raw3 v22c;
    RefCounted *rc238;
    char pad23c[4];
    Sub240 sub240;
    unsigned f248;

    void FUN_001d7ee0(int a);
    void FUN_001d6e10(RefCounted *a);
    void FUN_001d7510();
    void FUN_001d8d90(int a);
    unsigned FUN_001d72e0();

    char FUN_001da350(RefCounted *a1, Raw3 *a2, Raw3 *a3, unsigned a4, RefCounted *a5,
                      unsigned a6, unsigned a7, unsigned a8, unsigned a9, unsigned a10,
                      unsigned a11, RefCounted *a12, unsigned a13);
};

char Entity::FUN_001da350(RefCounted *a1, Raw3 *a2, Raw3 *a3, unsigned a4, RefCounted *a5,
                          unsigned a6, unsigned a7, unsigned a8, unsigned a9, unsigned a10,
                          unsigned a11, RefCounted *a12, unsigned a13)
{
    char ok = ready->FUN_001d4ef0();
    if (!ok)
        return ok;

    if (f114 != 0)
        FUN_001d7ee0(0);
    FUN_001d6e10(a1);
    FUN_001d7510();

    Raw3 *p;
    if (holder != 0)
        p = &holder->FUN_002fc6f0()->pos;
    else
        p = posSource->getPos();
    pos = *p;

    Mid10 *mid = holder ? holder->p10 : 0;
    Inner70 *in70 = mid->p70;
    if (in70 != 0)
        in70->FUN_002f5a20(a2);
    FUN_001d8d90(1);

    if (a1 != 0)
        a1->addRef();
    if (rc1fc != 0)
        rc1fc->release();
    rc1fc = a1;
    v200 = *a2;
    v20c = *a3;
    f218 = a4;
    if (a5 != 0)
        a5->addRef();
    if (rc21c != 0)
        rc21c->release();
    rc21c = a5;
    v220.a = a6;
    v220.b = a7;
    v220.c = a8;
    v22c.a = a9;
    v22c.b = a10;
    v22c.c = a11;
    if (a12 != 0)
        a12->addRef();
    if (rc238 != 0)
        rc238->release();
    rc238 = a12;
    sub240.FUN_0027af70(a13);
    f248 = 0;

    if (rc21c != 0 && DAT_004dd700 != 0) {
        Reg20 *r20 = DAT_004dd700->p20;
        if (r20 != 0) {
            Reg124 *r = r20->p124;
            if (r != 0 && r->key == a1)
                r20->FUN_00029b50(FUN_001d72e0(), (unsigned)rc21c, f218);
        }
    }
    return 1;
}
