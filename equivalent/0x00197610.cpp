// STATUS: equivalent (tools/equiv.py level 3: 3013 inputs, branch coverage 68/68)
// FUN_00197610 @ 0x00197610
extern "C" double __cdecl sqrt(double);

struct V3_197610 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(const V3_197610 *other, float eps);
};

struct Rng_197610 {
    unsigned int lo;
    unsigned int hi;
    float FUN_00078780();
};
Rng_197610 *__cdecl FUN_000964d0();

static float RandBits(Rng_197610 *r)
{
    unsigned int a = r->lo;
    a = (a & 0xffff) * 0x9069 + (a >> 16);
    r->lo = a;
    unsigned int b = r->hi;
    b = (b & 0xffff) * 0x4650 + (b >> 16);
    r->hi = b;
    unsigned int bits = (((r->lo << 16) + (b & 0xffff)) & 0x7fffff) | 0x3f800000;
    return *(float *)&bits;
}

struct Pos10_197610 {
    void FUN_00059a50(V3_197610 *out);
};

struct Target_197610 {
    char pad00[0x10];
    Pos10_197610 *f10;
    void FUN_000356c0(V3_197610 *out);
    void FUN_00035550(V3_197610 *out);
};

class Cfg_197610 {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual float c7();
    char pad04[0xf0 - 4];
    char bf0;
    char padf1[0xfd - 0xf1];
    char bfd;
    char bfe;
    char padff[0x100 - 0xff];
    V3_197610 v100;
    V3_197610 v10c;
    float f118;
    V3_197610 v11c;
    float f128;
    char b12c;
    char pad12d[3];
    float f130;
    float f134;
    void FUN_00192ea0(V3_197610 *out);
};

struct Fighter_197610 {
    int x;
};
struct Anchor_197610 {
    Fighter_197610 *FUN_00059a30();
};
struct Ref20_197610 {
    Anchor_197610 *FUN_000592a0();
};

struct Sink64 {
    void FUN_001d7590();
    V3_197610 *FUN_001d6b40();
    void FUN_001d7810(V3_197610 v);
};

struct World20_197610 {
    Target_197610 *FUN_00024280(int a, int b);
};
struct World {
    char pad00[0x20];
    World20_197610 *f20;
};
extern World *DAT_004dd700;

class Proj_197610 {
public:
    char pad00[0x1c];
    Cfg_197610 *cfg;
    Ref20_197610 *f20;
    V3_197610 f24;
    char pad30[0x50 - 0x30];
    Target_197610 *f50;
    char pad54[4];
    int f58;
    int f5c;
    char pad60[4];
    Sink64 *f64;
    char pad68[4];
    V3_197610 f6c;
    char pad78[0x84 - 0x78];
    float f84;
    float f88;
    float f8c;
    void FUN_00197610(float dt);
};

void Proj_197610::FUN_00197610(float dt)
{
    if (f20 == 0)
        return;
    Fighter_197610 *owner = f20->FUN_000592a0()->FUN_00059a30();
    if (!owner)
        return;
    f64->FUN_001d7590();
    World20_197610 *w = DAT_004dd700->f20;
    f50 = 0;
    if (w)
        f50 = w->FUN_00024280(f58, f5c);
    Target_197610 *tg = f50;
    if (!tg)
        return;
    Cfg_197610 *c = cfg;
    if (c->bfd) {
        if (c->bfe) {
            V3_197610 P;
            tg->f10->FUN_00059a50(&P);
            V3_197610 d;
            d.x = 0;
            d.y = 0;
            d.z = 0;
            tg->FUN_000356c0(&d);
            float len = d.FUN_0022d110();
            float sc;
            if (len <= 0.0f) {
                tg->FUN_00035550(&d);
                sc = 4.0f;
            } else if (len < 1.0f) {
                sc = 4.0f;
            } else {
                sc = len;
            }
            V3_197610 e = d;
            sc = sc * cfg->f118;
            e.x = e.x * sc;
            e.y = e.y * sc;
            float ez = sc * e.z;
            f6c.x = P.x + e.x;
            f6c.y = P.y + e.y;
            f6c.z = P.z + ez;
        } else {
            tg->f10->FUN_00059a50(&f6c);
        }
    }
    V3_197610 *p = f64->FUN_001d6b40();
    V3_197610 D;
    D.x = f6c.x - p->x;
    D.y = f6c.y - p->y;
    D.z = f6c.z - p->z;
    float v = f84;
    c = cfg;
    float k = 1.0f;
    float L = (float)sqrt(D.z * D.z + D.y * D.y + D.x * D.x);
    float ratio = f88 / c->c7();
    c = cfg;
    if (*(unsigned int *)&c->f134 != 0x3f800000) {
        if (!(ratio >= c->f134)) {
            f8c = f84;
        } else {
            if (c->bf0)
                return;
            v = f8c;
        }
    }
    if (v > dt)
        k = dt / v;
    V3_197610 E = D;
    E.FUN_0022d110();
    Rng_197610 *rnd = FUN_000964d0();
    double m;
    if (cfg->b12c)
        m = k * cfg->f130 * L;
    else
        m = k * cfg->f128;
    E.x = E.x * m;
    E.y = E.y * m;
    E.z = E.z * m;
    V3_197610 q = cfg->v100;
    if (!q.FUN_0022d2b0(&f24, 1e-05f)) {
        V3_197610 q5 = cfg->v100;
        E.x = q5.x + E.x;
        E.y = q5.y + E.y;
        E.z = q5.z + E.z;
    }
    V3_197610 q2 = cfg->v10c;
    if (!q2.FUN_0022d2b0(&f24, 1e-05f)) {
        V3_197610 q3;
        float vals[4];
        for (int i = 0; i < 4; i++) {
            q3 = cfg->v10c;
            vals[i] = rnd->FUN_00078780() * q3.x;
        }
        double mx = (vals[0] + vals[1] + vals[2] + vals[3]) * 0.25f;
        double my = ((RandBits(rnd) - 1.0f) * cfg->v10c.y
                     + (RandBits(rnd) - 1.0f) * cfg->v10c.y
                     + (RandBits(rnd) - 1.0f) * cfg->v10c.y
                     + (RandBits(rnd) - 1.0f) * cfg->v10c.y) * 0.25f;
        float mz = ((RandBits(rnd) - 1.0f) * cfg->v10c.z
                    + (RandBits(rnd) - 1.0f) * cfg->v10c.z
                    + (RandBits(rnd) - 1.0f) * cfg->v10c.z
                    + (RandBits(rnd) - 1.0f) * cfg->v10c.z) * 0.25f;
        E.x = mx + E.x;
        E.y = my + E.y;
        E.z = mz + E.z;
    } else {
        V3_197610 q4 = cfg->v11c;
        if (!q4.FUN_0022d2b0(&f24, 1e-05f)) {
            Target_197610 *t5 = f50;
            if (t5 && f64) {
                V3_197610 G;
                cfg->FUN_00192ea0(&G);
                V3_197610 &H = D;
                t5->f10->FUN_00059a50(&H);
                if (G.x > 0.0f) {
                    if (E.x > H.x)
                        E.x = E.x - G.x;
                    else if (E.x < H.x)
                        E.x = G.x + E.x;
                } else {
                    if (E.x < H.x)
                        E.x = E.x - G.x;
                    else if (E.x > H.x)
                        E.x = G.x + E.x;
                }
                if (G.y > 0.0f) {
                    if (E.y > H.y)
                        E.y = E.y - G.y;
                    else if (E.y < H.y)
                        E.y = G.y + E.y;
                } else {
                    if (E.y < H.y)
                        E.y = E.y - G.y;
                    else if (E.y > H.y)
                        E.y = G.y + E.y;
                }
                if (G.z > 0.0f) {
                    if (E.z > H.z)
                        E.z = E.z - G.z;
                    else if (E.z < H.z)
                        E.z = G.z + E.z;
                } else {
                    if (E.z < H.z)
                        E.z = E.z - G.z;
                    else if (E.z > H.z)
                        E.z = G.z + E.z;
                }
            }
        }
    }
    V3_197610 *pp = f64->FUN_001d6b40();
    V3_197610 X;
    X.x = E.x + pp->x;
    X.y = E.y + pp->y;
    X.z = E.z + pp->z;
    f64->FUN_001d7810(X);
    f84 = f84 - dt;
    f88 = dt + f88;
}
