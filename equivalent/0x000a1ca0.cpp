// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 38/38)
// FUN_000a1ca0 @ 0x000a1ca0
extern unsigned int DAT_004dd9f8;
extern unsigned __int64 DAT_004dd9f0;

unsigned __int64 __cdecl FUN_0027b020(const char *s) throw();
float __cdecl FUN_000a0450(void *v) throw();

union Bits_a1ca0 {
    float f;
    unsigned int u;
};

struct V3_a1ca0 {
    float x, y, z;
};

struct Fighter_a1ca0 {
    void FUN_00059a50(V3_a1ca0 *out);
};

struct Info_a1ca0 {
    char pad0[8];
    unsigned __int64 id;        // 0x08
};

struct Node {
    char pad0[0xec];
    Info_a1ca0 *info;                 // 0xec
};

struct Stats_a1ca0 {
    char pad0[0x10];
    Fighter_a1ca0 *fighter;           // 0x10
    char pad14[0x338 - 0x14];
    int f338;
    char pad33c[0x1a64 - 0x33c];
    Bits_a1ca0 f1a64;
    Node *FUN_00035ef0(int index);
    char FUN_00035550(V3_a1ca0 *out);
};

struct Holder124_a1ca0 {
    char pad0[0x124];
    Stats_a1ca0 *stats;
};

struct Owner_a1ca0 {
    char pad0[0x20];
    Holder124_a1ca0 *f20;
};

class Cam_a1ca0 {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual char *getTarget();
    char pad04[0x190];
    V3_a1ca0 v194;                    // 0x194
    char pad1a0[0x18];
    V3_a1ca0 v1b8;                    // 0x1b8
    V3_a1ca0 v1c4;                    // 0x1c4
    V3_a1ca0 v1d0;                    // 0x1d0
    V3_a1ca0 v1dc;                    // 0x1dc
    V3_a1ca0 v1e8;                    // 0x1e8
    char pad1f4[0xc];
    V3_a1ca0 v200;                    // 0x200
    char pad20c[8];
    int f214;
    char pad218[4];
    int f21c;
    char pad220[4];
    int f224;
    char pad228[4];
    int f22c;
    char pad230[4];
    Bits_a1ca0 dt234;                 // 0x234
    float f238;
    Bits_a1ca0 f23c;                  // 0x23c
    char pad240[0x5c];
    V3_a1ca0 v29c;                    // 0x29c
    V3_a1ca0 v2a8;                    // 0x2a8
    char pad2b4[0x345 - 0x2b4];
    char b345;
    char pad346;
    char b347;
    char b348;
    char pad349[3];
    float f34c;
    Stats_a1ca0 *stats;               // 0x350
    char pad354[0x448 - 0x354];
    int f448;
    char pad44c[4];
    float f450;
    float f454;
    float f458;
    char pad45c[0x488 - 0x45c];
    float f488;
    V3_a1ca0 *FUN_000a92c0(V3_a1ca0 *out, Owner_a1ca0 *owner, Stats_a1ca0 *st);
    void FUN_000a1b30(Owner_a1ca0 *owner, float dt, bool snap);
    void FUN_000a0fe0(float v);
    void FUN_000a1ca0(Owner_a1ca0 *owner, float dt);
};

void Cam_a1ca0::FUN_000a1ca0(Owner_a1ca0 *owner, float dt)
{
    struct Frame {
        V3_a1ca0 tmp1;
        V3_a1ca0 tmp2;
    } fr;

    dt234.f = dt;
    stats->fighter->FUN_00059a50(&v1b8);
    f23c = stats->f1a64;
    f23c.f = (f23c.f < -1000.0f) ? -1000.0f : f23c.f;

    Stats_a1ca0 *st = stats;
    v1c4 = *FUN_000a92c0(&fr.tmp1, owner, st);

    Bits_a1ca0 ab;
    ab.f = dt;
    ab.u &= 0x7fffffff;
    if (!(ab.f <= 0.00001f)) {
        double inv = 1.0f / dt;
        volatile V3_a1ca0 *d0 = &v1d0;
        volatile V3_a1ca0 *d1 = &v1dc;
        d0->x = v1c4.x - v29c.x;
        d0->y = v1c4.y - v29c.y;
        d0->z = v1c4.z - v29c.z;
        d0->x = inv * d0->x;
        d0->y = inv * d0->y;
        d0->z = inv * d0->z;
        d1->x = d0->x - v2a8.x;
        d1->y = d0->y - v2a8.y;
        d1->z = d0->z - v2a8.z;
        d1->x = inv * d1->x;
        d1->y = inv * d1->y;
        d1->z = inv * d1->z;
    }

    b345 = (stats == owner->f20->stats);
    v1e8 = v1c4;
    b347 = 0;
    b348 = 0;
    if (b345) {
        v200.x = v1c4.x - v29c.x;
        v200.y = v1c4.y - v29c.y;
        v200.z = v1c4.z - v29c.z;
        if (stats->f338 != 0)
            b347 = 1;
        if ((DAT_004dd9f8 & 1) == 0) {
            DAT_004dd9f8 |= 1;
            DAT_004dd9f0 = FUN_0027b020("gorilla_gorilla");
        }
        Node *n = stats->FUN_00035ef0(0);
        if (n != 0 && n->info->id == DAT_004dd9f0)
            b348 = 1;
    } else {
        v200.z = 0.0f;
        v200.y = 0.0f;
        v200.x = 0.0f;
    }

    f21c = f448;
    f224 = 0;
    f214 = 0;
    f22c = 0;
    v194 = *(V3_a1ca0 *)(getTarget() + 0x30);
    f238 = 0.0f;
    if (stats->FUN_00035550(&fr.tmp2))
        f238 = FUN_000a0450(&fr.tmp2);
    FUN_000a1b30(owner, dt, false);

    if (f458 != 0.0f) {
        float nv = dt * f458 + f450;
        if ((f458 > 0.0f && nv >= f454) || (f458 < 0.0f && nv < f454)) {
            nv = f454;
            f458 = 0.0f;
        }
        FUN_000a0fe0(nv);
    }
    if (f488 > 0.0f) {
        double r = f488 - dt;
        f488 = r;
        if (r < 0.0)
            f488 = 0.0f;
    }
    if (f34c > 0.0f) {
        double r = f34c - dt;
        f34c = r;
        if (r < 0.0)
            f34c = 0.0f;
    }
}
