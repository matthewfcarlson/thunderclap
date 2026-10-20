// STATUS: equivalent (tools/equiv.py level 3: 3130 inputs, branch coverage 131/132, incomplete)
// FUN_000418f0 @ 0x000418f0
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" double __cdecl sqrt(double);

struct V3_418f0 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(V3_418f0 *other, float eps);
};

struct RefObj_418f0 {
    virtual void AddRef();
    virtual void Release();
};

struct Sub10_418f0 {
    void FUN_00222120(V3_418f0 *out);
};

struct Mover_418f0 {
    char pad0[0x10];
    Sub10_418f0 s10;
    char pad14[0x40 - 0x14];
    V3_418f0 p40;
    void FUN_002226f0(V3_418f0 *pos);
    void FUN_00222700(float a);
};

struct Locator {
    char pad0[0x18];
    Mover_418f0 *f18;
    Mover_418f0 *FUN_00059a40();
    void FUN_00059a50(V3_418f0 *out);
};

struct Cell_418f0 {
    int FUN_00204200(float x, float y, float z);
    char FUN_00204440(int c);
};
struct Holder_418f0 {
    Cell_418f0 *FUN_000862a0();
};
struct Flt {
    float FUN_00099b70();
};
struct Ctx_418f0;
struct Chara_418f0;
struct Owner_418f0 {
    char pad0[0x124];
    Chara_418f0 *f124;
};
struct Ctx_418f0 {
    char pad0[8];
    Flt *f08;
    char pad0c[0x20 - 0xc];
    Owner_418f0 *f20;
    char pad24[0x54 - 0x24];
    Holder_418f0 *f54;
};

struct Ctrl_418f0 {
    char pad0[0x14];
    int f14;
    char pad18[0x34 - 0x18];
    float f34;
    unsigned __int64 FUN_000443c0();
};

struct Fx_418f0 {
    char FUN_0023f730(const char *s);
    void FUN_0023f740();
};

struct Ref14c : RefObj_418f0 {
    char pad4[8];
    int f0c;
};

float __cdecl FUN_00224ea0(float a, float b);
float __cdecl FUN_00224fc0(float a, float b);
V3_418f0 *__cdecl FUN_00083e00(V3_418f0 *out, V3_418f0 *in, float s);

struct Hit_418f0 {
    char FUN_00201e00(V3_418f0 *a, V3_418f0 *b, int c, V3_418f0 *d, V3_418f0 *e, int f, int g);
};
struct World {
    char pad0[0x24];
    Hit_418f0 *f24;
};

struct Sub14 {
    float FUN_002220d0();
};

struct Ref14c;
struct Frame_418f0 {
    V3_418f0 w88;
    float fl;
    Mover_418f0 *obj18;
    V3_418f0 w74;
    char pad68[2];
    char b66;
    char flag65;
    V3_418f0 w64;
    V3_418f0 w58;
    V3_418f0 A;
    Ref14c *D;
    V3_418f0 pos;
    float adiff;
    int ctype;
    V3_418f0 B;
    float thr;
    V3_418f0 w18;
    V3_418f0 cur;
};

class Chara_418f0 {
public:
    char pad000[0x10];
    Locator *f10;
    char pad14[0x44 - 0x14];
    V3_418f0 p44;
    char pad50[0x68 - 0x50];
    V3_418f0 p68;
    char pad74[0x84 - 0x74];
    float f84;
    char pad88[0x11c - 0x88];
    Ctrl_418f0 *f11c;
    char pad120[0x134 - 0x120];
    int f134;
    int f138;
    char pad13c[4];
    int mode;
    unsigned int f144;
    float f148;
    Ref14c *f14c;
    char pad150[0x1c0 - 0x150];
    float f1c0, f1c4, f1c8;
    char pad1cc[0x334 - 0x1cc];
    Chara_418f0 *ignoreA;
    Chara_418f0 *ignoreB;
    char pad33c[0x3a4 - 0x33c];
    RefObj_418f0 *f3a4;
    char pad3a8[0x1a38 - 0x3a8];
    char b1a38;
    char b1a39;
    char pad1a3a[2];
    V3_418f0 p1a3c;
    V3_418f0 p1a48;
    V3_418f0 p1a54;
    V3_418f0 p1a60;
    V3_418f0 p1a6c;
    V3_418f0 p1a78;
    V3_418f0 p1a84;
    char pad1a90[0x1ad4 - 0x1a90];
    V3_418f0 p1ad4;
    V3_418f0 p1ae0;
    V3_418f0 p1aec;
    V3_418f0 p1af8;
    int f1b04;
    char b1b08;
    char pad1b09[0x1b20 - 0x1b09];
    int f1b20;

    void FUN_00038c40();
    char FUN_00038c70(V3_418f0 *a, V3_418f0 *b, V3_418f0 *c, Ref14c **d, int e, char *f);
    void FUN_00035550(V3_418f0 *out);
    char FUN_0003f7b0(V3_418f0 *p1, V3_418f0 *p2, V3_418f0 *o1, V3_418f0 *o2, V3_418f0 *d, V3_418f0 *n2, unsigned int *flags);
    void FUN_000418f0(Ctx_418f0 *a1, float a2);
};

static float K1() { return 1.04719758f; }
static float K2() { return 0.52359879f; }

void Chara_418f0::FUN_000418f0(Ctx_418f0 *a1, float a2)
{
    Frame_418f0 f;
    f.obj18 = f10->FUN_00059a40();
    f.pos.x = 0.0f;
    f.pos.y = 0.0f;
    f.pos.z = 0.0f;
    f10->FUN_00059a50(&f.pos);
    f.cur.x = p44.x;
    f.cur.y = p44.y;
    f.cur.z = p44.z;
    Chara_418f0 *own = a1->f20->f124;
    f.b66 = 0;
    if (!(own == this || ignoreA == own || ignoreB == own)) {
        Cell_418f0 *cell = a1->f54->FUN_000862a0();
        int idx = cell->FUN_00204200(f.pos.x, f.pos.y, f.pos.z);
        if (!a1->f54->FUN_000862a0()->FUN_00204440(idx))
            return;
    } else {
        f.b66 = 1;
    }
    f.fl = f148;
    f.thr = f.fl * 0.5f;
    f.ctype = f11c->f14;
    (*(Fx_418f0**)&DAT_004dd6e8)->FUN_0023f730("World Collision Manager");
    (*(Fx_418f0**)&DAT_004dd6e8)->FUN_0023f740();
    if (f1b20 > 0 || (f14c != 0 && f14c->f0c != 5 && f14c->f0c == 0))
        FUN_00038c40();
    b1a38 = b1a39;
    f.D = 0;
    f.flag65 = 0;
    f.B.x = 0.0f;
    char hit = FUN_00038c70(&f.A, &f.B, &f.w64, &f.D, 0, &f.flag65);
    b1a39 = hit;
    Ref14c *obj = 0;
    if (hit) {
        p1a3c = f.A;
        p1a48 = f.A;
        char bl = 0;
        if (f.b66) {
            if (f.A.y >= a1->f08->FUN_00099b70())
                bl = 1;
        }
        int ty = mode;
        int path;
        if (ty == 3 || ty == 4) {
            path = 2;
        } else if (bl) {
            path = 3;
        } else {
            f.adiff = f.pos.y - f.A.y;
            if (f.adiff < 0.0f)
                f.adiff = -f.adiff;
            if (f.adiff > f.fl || f.B.y < 0.5f)
                path = 3;
            else
                path = 1;
        }
        if (path == 1) {
            f144 = f144 | 1;
            if (f.ctype != 5)
                f.obj18->FUN_002226f0(&f.A);
            if (!f.flag65) {
                p1a54 = f.A;
                p1a78 = f.B;
            }
            obj = f.D;
        } else if (path == 2) {
            if (!bl && (f.pos.y - f.A.y) < f.fl && f.B.y > 0.5f) {
                f144 = f144 | 1;
                p1a54 = f.A;
                p1a78 = f.B;
                obj = f.D;
            } else if (ty == 3 && (f.pos.y - f.A.y) < f.fl) {
                f.w88.x = f.B.x;
                f.w88.y = 0.0f;
                f.w88.z = f.B.z;
                f.w88.FUN_0022d110();
                float k = -f84;
                if (!(40.0f < k))
                    k = 40.0f;
                float g = k * a2;
                f.w88.y = g * f.w88.y;
                f.w88.z = f.w88.z * g;
                f1c0 = f.w88.x * g + f1c0;
                f1c4 = f.w88.y + f1c4;
                f1c8 = f.w88.z + f1c8;
            }
        } else {
            f.A = p1a54;
            f.B = p1a78;
            if (ignoreB == 0 && !(f1b20 > 0)) {
                f.w58.x = p44.x;
                f.w58.y = p44.y;
                f.w58.z = p44.z;
                f.w88.x = p1a54.x - f.w58.x;
                f.w88.y = p1a54.y - f.w58.y;
                f.w88.z = p1a54.z - f.w58.z;
                if (f.w88.FUN_0022d110() < a2) {
                    f.w74 = p1a54;
                } else {
                    f.w74.x = f.w88.x * a2 + f.w58.x;
                    f.w74.y = f.w88.y * a2 + f.w58.y;
                    f.w74.z = f.w88.z * a2 + f.w58.z;
                }
                f.obj18->FUN_002226f0(&f.w74);
                FUN_00038c40();
            }
        }
        p1a60 = f.A;
        p1a6c = f.B;
        p1a84 = f.w64;
        if ((mode == 3 || mode == 4) && ignoreB == 0 && !(f1b20 > 0)) {
            float lim = f.A.y + f.thr;
            if (f134 == 7 || f.ctype == 5)
                lim = lim - f.thr;
            if (f.pos.y < lim) {
                f.pos.y = lim;
                f.obj18->FUN_002226f0(&f.pos);
            }
        } else {
            if (f.pos.y < f.A.y) {
                f.pos.y = f.A.y;
                f.obj18->FUN_002226f0(&f.pos);
            }
        }
        if (f11c->FUN_000443c0() == (*(unsigned __int64*)&DAT_004dc060) ||
            (f11c->FUN_000443c0() == (*(unsigned __int64*)&DAT_004dc090) && f138 > 0)) {
            if (f.pos.y < f.A.y) {
                f.pos.y = f.A.y;
                f.obj18->FUN_002226f0(&f.pos);
            } else {
                float lim2 = f.A.y + 0.25f;
                if (f.pos.y > lim2) {
                    f.pos.y = lim2;
                    f.obj18->FUN_002226f0(&f.pos);
                }
            }
        }
        if (obj)
            obj->AddRef();
        if (f14c)
            f14c->Release();
        f14c = obj;
        if (obj == (Ref14c *)f3a4) {
            if (f3a4)
                f3a4->Release();
            f3a4 = 0;
        }
    } else {
        if (f14c) {
            f14c->Release();
            f14c = 0;
        }
        if (mode != 3 && mode != 4 && ignoreB == 0 && !(f1b20 > 0)) {
            f.w64.x = p44.x;
            f.w64.y = p44.y;
            f.w64.z = p44.z;
            f.obj18->FUN_002226f0(&f.w64);
        }
    }

    if (mode != 4) {
        p1af8.z = 0.0f;
        p1af8.y = 0.0f;
        p1af8.x = 0.0f;
        b1b08 = 0;
        return;
    }
    f.w64.x = 0.0f;
    f.w64.y = 0.0f;
    f.w64.z = 0.0f;
    if (p1af8.FUN_0022d2b0(&f.w64, 1e-005f)) {
        f.w64.x = 0.0f;
        f.w64.y = 0.0f;
        f.w64.z = 0.0f;
        if (!p1ae0.FUN_0022d2b0(&f.w64, 1e-005f)) {
            p1aec = p1ad4;
            p1af8 = p1ae0;
            p1ad4.x = 0.0f; p1ad4.y = 0.0f; p1ad4.z = 0.0f;
            p1ae0.x = 0.0f; p1ae0.y = 0.0f; p1ae0.z = 0.0f;
            f.obj18->FUN_002226f0(&p1aec);
            f.obj18->FUN_00222700(FUN_00224ea0(-p1af8.x, -p1af8.z));
            b1b08 = 1;
        } else {
            f.thr = f11c->f34;
            FUN_00035550(&f.w74);
            f.w88.x = f.w74.x;
            f.w88.y = f.w74.y;
            f.w88.z = f.w74.z;
            float ns = -f.thr;
            f.w74.y = f.w74.y * ns;
            f.w74.z = f.w74.z * ns;
            f.w74.x = f.w74.x * ns + f.obj18->p40.x;
            f.w74.y = f.w74.y + f.obj18->p40.y;
            f.w74.z = f.w74.z + f.obj18->p40.z;
            float k = f.thr * 4.5f;
            f.w88.x = f.w88.x * k + f.w74.x;
            f.w88.y = f.w88.y * k + f.w74.y;
            f.w88.z = f.w88.z * k + f.w74.z;
            char ok = FUN_0003f7b0(&f.w74, &f.w88, &p1aec, &p1af8, 0, 0, 0);
            b1b08 = ok;
            if (ok) {
                f.obj18->FUN_002226f0(&p1aec);
                f.obj18->FUN_00222700(FUN_00224ea0(-p1af8.x, -p1af8.z));
            }
        }
    } else {
        f.thr = f11c->f34;
        f.w74.x = f.thr * p1af8.x + f.obj18->p40.x;
        f.w74.y = f.thr * p1af8.y + f.obj18->p40.y;
        f.w74.z = f.thr * p1af8.z + f.obj18->p40.z;
        f.w88.x = p1af8.x;
        f.w88.y = p1af8.y;
        f.w88.z = p1af8.z;
        f.w58.x = f.pos.x;
        f.w58.y = f.pos.y;
        f.w58.z = f.pos.z;
        float m3 = f.thr * -3.0f;
        f.w88.x = f.w88.x * m3 + f.w74.x;
        f.w88.y = f.w88.y * m3 + f.w74.y;
        f.w88.z = f.w88.z * m3 + f.w74.z;
        f.w58.x = f.w58.x - f.cur.x;
        f.w58.y = f.w58.y - f.cur.y;
        f.w58.z = f.w58.z - f.cur.z;
        f.w58.FUN_0022d110();
        f.w64.x = p1af8.x;
        f.w64.y = p1af8.y;
        f.w64.z = p1af8.z;
        f.w18.x = p1aec.x;
        f.w18.y = p1aec.y;
        f.w18.z = p1aec.z;
        char ok = FUN_0003f7b0(&f.w74, &f.w88, &f.w18, &f.w64, &p1af8, &f.w58, (unsigned int *)&f1b04);
        b1b08 = ok;
        if (ok) {
            p1aec = f.w18;
            f.obj18->FUN_002226f0(&p1aec);
            p1af8 = f.w64;
            float ang0 = ((Sub14 *)((char *)this + 0x14))->FUN_002220d0();
            float ang1 = FUN_00224ea0(-p1af8.x, -p1af8.z);
            static float k1 = K1();
            f.fl = k1 * a2;
            float dif = FUN_00224fc0(ang0, ang1);
            float adif = dif < 0.0f ? -dif : dif;
            if (adif <= f.fl)
                f.fl = ang1;
            else if (dif < 0.0f)
                f.fl = ang0 - f.fl;
            else
                f.fl = f.fl + ang0;
            static float k2 = K2();
            float res = FUN_00224fc0(ang1, f.fl);
            if (res < -k2)
                f.fl = ang1 - k2;
            else if (res > k2)
                f.fl = ang1 + k2;
            f.obj18->FUN_00222700(f.fl);
        } else {
            if (f1b04 != 0)
                b1b08 = 1;
            f.obj18->FUN_002226f0(&p1aec);
            f.obj18->FUN_00222700(FUN_00224ea0(-p1af8.x, -p1af8.z));
        }
    }

    f.w18.x = p68.x;
    f.w18.y = p68.y;
    f.w18.z = p68.z;
    f.w58.x = f.obj18->p40.x;
    f.w58.y = f.obj18->p40.y;
    f.w58.z = f.obj18->p40.z;
    f.w64.x = 0.0f;
    f.w64.y = 0.0f;
    f.w64.z = 0.0f;
    Mover_418f0 *m2 = f10->FUN_00059a40();
    float xx, zz;
    if (m2) {
        m2->s10.FUN_00222120(&f.w88);
        f.w64.y = f.w88.y;
        xx = f.w88.x;
        zz = f.w88.z;
    } else {
        xx = f.w64.x;
        zz = f.w64.z;
    }
    float ns2 = -f11c->f34;
    f.w58.x = ns2 * xx + f.w58.x;
    f.w58.y = f.w64.y * ns2 + f.w58.y;
    f.w58.z = zz * ns2 + f.w58.z;
    if (!f.w18.FUN_0022d2b0(&f.w58, 1e-005f)) {
        if (DAT_004dd700->f24->FUN_00201e00(&f.w18, &f.w58, 0, &f.w88, &f.w64, 0, 0))
            f.obj18->FUN_002226f0(&f.cur);
    }
}
