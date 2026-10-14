// STATUS: equivalent (tools/equiv.py level 3: 3113 inputs, branch coverage 88/90, incomplete)
// FUN_0003d350 @ 0x0003d350
extern int DAT_004d2a3c;
extern char DAT_004d2a40;
extern char DAT_00554c1c;
extern int DAT_00554c18;

struct V3_3d350 {
    float x, y, z;
    float FUN_0022d110();
    char FUN_0022d2b0(const V3_3d350 *other, float eps);
    void FUN_00011160(float s, const V3_3d350 *d);
    char FUN_000375a0();
};

char __cdecl FUN_002027c0(V3_3d350 *from, V3_3d350 *to, int a, int b, V3_3d350 *hitPos, V3_3d350 *hitNormal, int c, int d);

class Fighter_3d350;

struct Mover_3d350 {
    void FUN_002226f0(V3_3d350 *v);
};
struct Slot74 {
    char pad00[0x72];
    char b72;
};
struct Rig12c {
    char pad00[0x74];
    Slot74 *f74;
};
struct Obj1d72_3d350 {
    char pad00[0x74];
    Slot74 *f74;
};
struct Obj128_3d350 {
    Obj1d72_3d350 *FUN_001d72e0();
};
struct Hold10 {
    Mover_3d350 *FUN_00059a40();
    void FUN_00059a50(V3_3d350 *out);
};
struct Gear_3d350 {
    char pad00[0x10];
    char b10;
    char pad11[0x30 - 0x11];
    float f30;
    float f34;
};
struct Ez {
    char pad00[0x18];
    int f18;
};
struct Ey {
    float f0;
    Ez *f4;
};
struct Ex {
    char pad00[8];
    Ey *f8;
};
struct Ee {
    char FUN_002ee140(Ex *e, V3_3d350 *a, V3_3d350 *b, int z);
};
struct Wld {
    char pad00[8];
    Ee *f8;
};
struct Holder20_3d350 {
    char pad00[0x124];
    Fighter_3d350 *f124;
};
struct Hit202 {
    char FUN_00202460(V3_3d350 *from, V3_3d350 *dir, float len, int c, V3_3d350 *o1, V3_3d350 *o2, int d, int e);
};
struct Arg1_3d350 {
    char pad00[0x10];
    Wld *f10;
    char pad14[0x20 - 0x14];
    Holder20_3d350 *f20;
    Hit202 *f24;
};

Ex *__cdecl FUN_00202f00();

class Fighter_3d350 {
public:
    char pad00[0x10];
    Hold10 *f10;
    char pad14[0x44 - 0x14];
    V3_3d350 p44;
    char pad50[0x68 - 0x50];
    V3_3d350 r68;
    char pad74[0x11c - 0x74];
    Gear_3d350 *f11c;
    char pad120[0x128 - 0x120];
    Obj128_3d350 *f128;
    Rig12c *f12c;
    char pad130[0x140 - 0x130];
    int mode;
    int f144;
    char pad148[0x14c - 0x148];
    int f14c;
    char pad150[0x1c0 - 0x150];
    float f1c0;
    float f1c4;
    float f1c8;
    char pad1cc[0x334 - 0x1cc];
    Fighter_3d350 *f334;
    Fighter_3d350 *f338;
    char pad33c[0x1b20 - 0x33c];
    int f1b20;

    void FUN_00035fa0(int a);
    void FUN_00035550(V3_3d350 *out);
    void FUN_000350c0(V3_3d350 *out);
    void FUN_0003d1c0(int a, unsigned int b, V3_3d350 *c, V3_3d350 *d);
    Obj128_3d350 *FUN_dummy128();
    void Update(Arg1_3d350 *a1, float a2);
};

void Fighter_3d350::Update(Arg1_3d350 *a1, float a2)
{
    if (f1b20 > 0)
        return;
    Mover_3d350 *mv = f10->FUN_00059a40();
    V3_3d350 p;
    p.x = 0;
    p.y = 0;
    p.z = 0;
    f10->FUN_00059a50(&p);
    V3_3d350 q = p44;
    Hit202 *a1f24 = a1->f24;
    V3_3d350 pc;
    float len;
    V3_3d350 hitV;
    if (f338 != 0) {
        V3_3d350 c;
        c.x = 0;
        c.y = 0;
        c.z = 0;
        f338->FUN_000350c0(&c);
        V3_3d350 c2 = c;
        V3_3d350 pcopy = p;
        V3_3d350 d;
        d.x = p.x - c2.x;
        d.y = p.y - c2.y;
        d.z = p.z - c2.z;
        len = d.FUN_0022d110();
        if (!(len > 0.0f))
            return;
        f338->FUN_00035fa0(0);
        FUN_00035fa0(0);
        V3_3d350 hitPos;
        V3_3d350 hitNormal;
        if (FUN_002027c0(&c2, &pcopy, 0, 0, &hitPos, &hitNormal, 0, 0)) {
            hitV = hitPos;
            if (hitNormal.y < 0.5f) {
                if (len > 0.1f) {
                    hitV.x = hitPos.x - c2.x;
                    hitV.y = hitPos.y - c2.y;
                    hitV.z = hitPos.z - c2.z;
                    float L = hitV.FUN_0022d110();
                    float sc = L - 0.1f;
                    hitV.x = hitV.x * sc + c2.x;
                    hitV.y = hitV.y * sc + c2.y;
                    hitV.z = hitV.z * sc + c2.z;
                } else {
                    hitV = c;
                }
            }
            mv->FUN_002226f0(&hitV);
        }
        FUN_00035fa0(1);
        f338->FUN_00035fa0(1);
        return;
    }

    if (f14c == 0 && f144 == 0) {
        if (p.FUN_0022d2b0(&q, 1e-05f))
            return;
    }
    if (f128 != 0)
        return;

    V3_3d350 dd;
    dd.x = p.x - q.x;
    dd.y = p.y - q.y;
    dd.z = p.z - q.z;
    float lenSq = dd.x * dd.x + dd.y * dd.y + dd.z * dd.z;
    Fighter_3d350 *cur = a1->f20->f124;
    union { unsigned int w; unsigned char b; } flag34;
    if (cur == this || f334 == cur || f338 == cur)
        flag34.b = 1;
    else
        flag34.b = 0;
    char al = (f334 != 0 || f338 != 0) ? 1 : 0;
    int bl = flag34.b;
    int ebx;
    if (!bl) {
        Gear_3d350 *g = f11c;
        ebx = 0;
        if (!g->b10 && mode != 3 && al == 0) {
            if (lenSq < 1.0f)
                return;
        }
    } else {
        ebx = 0;
    }
    Gear_3d350 *gear = f11c;
    float g30 = gear->f30;
    float g34 = gear->f34;
    V3_3d350 r = r68;
    V3_3d350 P3 = p;
    if (mode == 1 || mode == 2) {
        P3.y = g30 * 0.5f + P3.y;
    } else if (mode == 4) {
        V3_3d350 s;
        s.x = 0;
        s.y = 0;
        s.z = 0;
        FUN_00035550(&s);
        P3.FUN_00011160(-g34, &s);
    }
    V3_3d350 D;
    D.x = P3.x - r.x;
    D.y = P3.y - r.y;
    D.z = P3.z - r.z;
    float dl = D.FUN_0022d110();
    V3_3d350 U = D;
    P3.x = D.x * dl;
    P3.y = D.y * dl;
    P3.z = D.z * dl;
    if (mode != 4)
        U.y = 0;
    float ux = U.x * g34;
    float uy = U.y * g34;
    float uz = U.z * g34;
    P3.x = ux + P3.x;
    P3.y = uy + P3.y;
    P3.z = uz + P3.z;
    P3.x = P3.x + r.x;
    P3.y = r.y + P3.y;
    P3.z = P3.z + r.z;
    D.x = P3.x - r.x;
    D.y = P3.y - r.y;
    D.z = P3.z - r.z;
    float len2 = D.FUN_0022d110();
    if (!D.FUN_000375a0())
        return;

    V3_3d350 o1, o2;
    if (a1f24->FUN_00202460(&r, &D, len2, !flag34.b, &o1, &o2, 0, 0)) {
        if (mode == 3 && o2.y > 0.5f) {
            V3_3d350 H = o1;
            mv->FUN_002226f0(&H);
            return;
        }
        V3_3d350 W = q;
        if (mode != 4) {
            if (p.y <= q.y)
                W.y = p.y;
        }
        mv->FUN_002226f0(&W);
        p = W;
        V3_3d350 N = o2;
        if (!(mode == 3 && o2.y < 0.0f)) {
            N.y = 0;
            N.FUN_0022d110();
        }
        float s = a2 * 10.0f;
        f1c0 = N.x * s + f1c0;
        f1c4 = s * N.y + f1c4;
        f1c8 = N.z * s + f1c8;
        return;
    }

    Ex *ob = FUN_00202f00();
    DAT_004d2a3c = 2;
    DAT_004d2a40 = 0;
    DAT_00554c1c = 1;
    DAT_00554c18 = 0;
    Ee *world = a1->f10->f8;
    f12c->f74->b72 = 0;
    if (f128)
        f128->FUN_001d72e0()->f74->b72 = 0;
    if (f334) {
        f334->f12c->f74->b72 = 0;
        if (f334->f128)
            f334->f128->FUN_001d72e0()->f74->b72 = 0;
        f334->FUN_00035fa0(0);
    }
    if (f338) {
        f338->f12c->f74->b72 = 0;
        if (f338->f128)
            f338->f128->FUN_001d72e0()->f74->b72 = 0;
        f338->FUN_00035fa0(0);
    }
    FUN_00035fa0(0);
    if (world->FUN_002ee140(ob, &r, &P3, 0)) {
        if (ob->f8->f0 > 0.0f)
            FUN_0003d1c0(ob->f8->f4->f18, flag34.w, &q, &p);
    }
    FUN_00035fa0(1);
    if (f338) {
        f338->FUN_00035fa0(1);
        if (f338->f128)
            f338->f128->FUN_001d72e0()->f74->b72 = 1;
        f338->f12c->f74->b72 = 1;
    }
    if (f334) {
        f334->FUN_00035fa0(1);
        if (f334->f128)
            f334->f128->FUN_001d72e0()->f74->b72 = 1;
        f334->f12c->f74->b72 = 1;
    }
    if (f128)
        f128->FUN_001d72e0()->f74->b72 = 1;
    f12c->f74->b72 = 1;
}
