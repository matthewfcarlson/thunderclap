// STATUS: equivalent (tools/equiv.py level 3: 3180 inputs, branch coverage 118/140, incomplete)
// FUN_001bcef0 @ 0x001bcef0
extern "C" double __cdecl sqrt(double);
extern "C" void * __cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

extern unsigned char DAT_004dd888;
extern char DAT_0049fd74[];
extern char DAT_004c4bb4[];
extern float DAT_004c4be0;
extern float DAT_004c4be4;

struct Mat;
struct V3 {
    float x, y, z;
    float FUN_0022d110();
    void FUN_0022d210(Mat *m);
};

struct Mat {
    float m[16];
    void FUN_0022b980();
    void FUN_0022bab0(float a);
};

struct Item {
    virtual void i0(); virtual void i1(); virtual void i2(); virtual void i3(); virtual void i4();
    virtual void i5(); virtual void i6(); virtual void i7(); virtual void i8(); virtual void i9();
    virtual void i10();
    virtual float v11();
    virtual void v12(float a);
};

struct Group {
    char pad0[8];
    unsigned char b8;
    char pad9[0x18 - 9];
    unsigned char *f18;
    char pad1c[0x24 - 0x1c];
    Item **f24;
};

struct Node {
    virtual void n0(); virtual void n1(); virtual void n2(); virtual void n3(); virtual void n4();
    virtual void n5();
    virtual void v6(int a, int b);
    virtual void n7();
    virtual void v8(int a, int b);
    char pad04[0x44];
    Group *f48;
};

struct Renderer {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5();
    virtual void r6();
    virtual void r7();
    virtual void r8();
    virtual void r9();
    virtual void r10();
    virtual void r11();
    virtual void r12();
    virtual void r13();
    virtual void r14();
    virtual void r15();
    virtual void r16();
    virtual void r17();
    virtual void r18();
    virtual void r19();
    virtual void r20();
    virtual void r21();
    virtual void r22();
    virtual void r23();
    virtual void v24(V3 *p, V3 *a, V3 *b);
};

struct Dev {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void v13(int a);
    virtual void d14();
    virtual void v15(int a);
    virtual void v16(int a);
    virtual void v17(int a, Mat *m);
};

struct Wrapper {
    Dev *dev;
    void FUN_00293d00(V3 *v);
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293c20(float a);
};

struct Dev2 {
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual void e19();
    virtual void e20();
    virtual void e21();
    virtual void e22();
    virtual void e23();
    virtual void e24();
    virtual void e25();
    virtual void e26();
    virtual void e27();
    virtual void e28();
    virtual void e29();
    virtual void e30();
    virtual void e31();
    virtual void e32();
    virtual void e33();
    virtual void e34();
    virtual void e35();
    virtual void e36();
    virtual void e37();
    virtual void e38();
    virtual void e39();
    virtual void e40();
    virtual void e41();
    virtual void e42();
    virtual void e43();
    virtual void e44();
    virtual void e45();
    virtual void e46();
    virtual void e47();
    virtual void e48();
    virtual void e49();
    virtual void e50();
    virtual void e51();
    virtual void e52();
    virtual void e53();
    virtual void e54();
    virtual void e55();
    virtual void e56();
    virtual void e57();
    virtual void e58();
    virtual void e59();
    virtual void v60(int a);
    virtual int v61();
    virtual void v62(int a);
    virtual char v63();
};

extern Wrapper *DAT_0052c2ac;
extern Dev2 *DAT_0052c2a8;

struct Holder {
    Renderer *FUN_001c19a0();
    Mat *FUN_001c12c0();
};
Holder **FUN_001c3d90();
float __cdecl FUN_00018a20(float v);
char FUN_00035da0();

struct Obj3c {
    char FUN_000d6fd0();
    int FUN_000d6f50();
};

struct Obj8 {
    char FUN_000997a0();
};

class Zone;

struct Ready {
    int FUN_001d60c0();
};

struct Entity {
    char pad0[0x20];
    int f20;
    char pad24[0xec - 0x24];
    Ready *ready;
    char padf0[0x114 - 0xf0];
    void *f114;
    char pad118[0x148 - 0x118];
    Entity *f148;
    char pad14c[0x1b0c - 0x14c];
    float f1b0c;
    float f1b10;
    int FUN_001d62d0();
};

struct Target {
    char pad0[0x8];
    Entity *ent;
    int type;
};

struct Obj124 {
    char pad0[0x12c];
    void *f12c;
    char pad130[0x328 - 0x130];
    Target *f328;
    char pad32c[0x1fa0 - 0x32c];
    int f1fa0;
};

struct Obj20 {
    char pad0[0x124];
    Obj124 *f124;
    char pad128[0x350 - 0x128];
    char b350;
    char b351;
    void FUN_001bc3e0(V3 *out);
    char FUN_00029a90();
};

struct Dir {
    char pad0[0x10];
    float x, y, z;
};

struct Obj40 {
    char pad0[4];
    Node *f04;
    Node *f08;
    Node *f0c;
    Node *f10;
    Node *f14;
    struct Dir *f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    void FUN_001bcc30();
};

struct World {
    char pad0[8];
    Obj8 *f8;
    char pad0c[0x20 - 0xc];
    Obj20 *f20;
    char pad24[0x3c - 0x24];
    Obj3c *f3c;
    Obj40 *f40;
};
extern World *DAT_004dd700;

struct Frame {
    char pad00[3];
    char b13;
    union { volatile float f; float ang; int a; Node *eb; } u4;
    union { Obj40 *p40; float r; int n; } u8;
    V3 v;
    union { Obj20 *o20; float ang2; float arg; } u18;
    V3 P;
    union { volatile float e; int n; Node *eb; } u28;
    union { V3 o3; struct { float A; float padc8; float C; float D; } ac; } u2c;
    union { Renderer *R; int i; } u3c;
    float k;
    V3 vb4;
    V3 va8;
    void *self;
    union { char b; unsigned int dw; } u60;
    int prevI;
    union { Mat M2; V3 c[4]; } u68;
    float arr2[4];
    Mat mat;
};

static float K0557() { return 0.5569999814033508f; }
static float K003() { return 0.030000001192092896f; }
static float K003975() { return 0.039750002324581146f; }

static __forceinline void ApplyGroup(Node *n, char *on)
{
    Group *g = n->f48;
    if (g) {
        unsigned char cnt = g->b8;
        for (unsigned char i = 0; i < cnt; i++) {
            Item *it = g->f24[g->f18[i]];
            if (it) {
                if (*on)
                    it->v12(1.0f);
                else
                    it->v12(0.0f);
            }
        }
        n->v6(0, 0);
    }
}

class Fx {
public:
    void FUN_001bc730();
    void FUN_001bcef0();
};

void Fx::FUN_001bcef0()
{
    Frame f;
    f.self = this;
    if (DAT_004dd888)
        return;
    World *w = DAT_004dd700;
    Obj3c *p3c = w->f3c;
    if (!w->f8->FUN_000997a0())
        return;
    if (!p3c->FUN_000d6fd0())
        return;
    if ((p3c->FUN_000d6f50() & 0xfffffc7f) == 0)
        return;

    f.u60.b = DAT_0052c2a8->v63();
    DAT_0052c2a8->v62(0);
    f.prevI = DAT_0052c2a8->v61();
    DAT_0052c2a8->v60(1);
    f.u18.o20 = w->f20;
    f.u8.p40 = w->f40;
    Holder *h = *FUN_001c3d90();
    f.u3c.R = h->FUN_001c19a0();
    f.u8.p40->FUN_001bcc30();
    Obj20 *o20 = f.u18.o20;
    if (o20->b351) {
        Node *o14 = f.u8.p40->f14;
        if (o14) {
            Mat *m = h->FUN_001c12c0();
            f.mat = *m;
            o20->FUN_001bc3e0(&f.v);
            f.v.FUN_0022d210(&f.mat);
            f.v.z = 0.0f;
            f.v.FUN_0022d110();
            f.u8.r = FUN_00018a20(f.v.y);
            f.u4.f = f.u8.r * 0.63662f - 1.0f;
            f.u4.f = f.u4.f < 0.0f ? -f.u4.f : f.u4.f;
            float s = 1.0f - f.u4.f * 0.25f;
            f.v.x = f.v.x * s;
            f.v.y = s * f.v.y;
            if (f.v.x > 0.0f)
                f.u8.r = -f.u8.r;
            f.u68.M2.FUN_0022b980();
            f.u68.M2.FUN_0022bab0(f.u8.r);
            DAT_0052c2ac->dev->v15(0);
            DAT_0052c2ac->dev->v13(0);
            f.v.z = DAT_004c4be4;
            DAT_0052c2ac->FUN_00293d00(&f.v);
            DAT_0052c2ac->dev->v17(0, &f.u68.M2);
            DAT_0052c2ac->FUN_00293da0(DAT_004c4be0, DAT_004c4be0, DAT_004c4be0);
            o14->v8(0, 0);
            DAT_0052c2ac->dev->v16(0);
        }
    } else if (o20->b350) {
        Obj124 *p124 = o20->f124;
        if (p124) {
            Target *t = p124->f328;
            char ok = FUN_00035da0();
            if (t && (ok || p124->f1fa0 == 2 || p124->f1fa0 == 1)) {
                f.k = 1.0f;
                f.b13 = 0;
                int ty = t->type;
                if (ty == 1) {
                    Entity *ent = t->ent;
                    if (ent) {
                        if (ent->f1b10 > 0.0f)
                            f.k = ent->f1b0c / ent->f1b10;
                    }
                } else if (ty == 5) {
                    Entity *ent = t->ent;
                    if (ent) {
                        Entity *e2 = ent->f148;
                        if (e2) {
                            if (e2->f1b10 > 0.0f)
                                f.k = e2->f1b0c / e2->f1b10;
                        } else {
                            f.u4.a = ent->FUN_001d62d0();
                            f.u28.n = ent->ready->FUN_001d60c0();
                            if (f.u28.n > 0)
                                f.k = (float)f.u4.a / f.u28.n;
                            void *r = ent->f114;
                            if (r == 0 || r == p124->f12c)
                                f.b13 = 1;
                            else
                                f.b13 = 0;
                        }
                    }
                } else if (ty == 7) {
                    Entity *ent = t->ent;
                    if (ent) {
                        f.k = 1.0f;
                        if (ent->f20 <= 0)
                            f.k = 0.0f;
                        f.b13 = 1;
                    }
                }

                Obj40 *p40 = f.u8.p40;
                f.u2c.ac.A = p40->f1c;
                float Bp = p40->f20;
                f.u2c.ac.C = p40->f24;
                f.u2c.ac.D = p40->f28;
                static float lim0 = K0557();
                if (f.u2c.ac.A < -lim0)
                    f.u2c.ac.A = -lim0;
                if (f.u2c.ac.C > lim0)
                    f.u2c.ac.C = lim0;
                static float lim1 = K0557();
                if (Bp > lim1)
                    Bp = lim1;
                if (f.u2c.ac.D < -lim1)
                    f.u2c.ac.D = -lim1;
                static float lim2 = K003();
                f.u28.e = f.u2c.ac.C - f.u2c.ac.A;
                float u = f.u28.e - (lim2 + lim2);
                if (u < 0.0f) {
                    float hh = u * 0.5f;
                    f.u2c.ac.A = f.u2c.ac.A + hh;
                    f.u2c.ac.C = f.u2c.ac.C - hh;
                    f.u28.e = f.u2c.ac.C - f.u2c.ac.A;
                }
                static float lim3 = K003975();
                f.u4.f = Bp - f.u2c.ac.D;
                float v2 = f.u4.f - (lim3 + lim3);
                if (v2 < 0.0f) {
                    Bp = Bp - v2 * 0.5f;
                    double Dn = v2 * 0.5f + f.u2c.ac.D;
                    f.u2c.ac.D = (float)Dn;
                    f.u4.f = Bp - Dn;
                }
                f.u68.c[0].x = f.u2c.ac.A;
                f.u68.c[0].y = Bp;
                f.u68.c[0].z = 0.0f;
                f.u68.c[1].x = f.u2c.ac.C;
                f.u68.c[1].y = Bp;
                f.u68.c[1].z = 0.0f;
                f.u68.c[2].x = f.u2c.ac.C;
                f.u68.c[2].y = f.u2c.ac.D;
                f.u68.c[2].z = 0.0f;
                f.u68.c[3].x = f.u2c.ac.A;
                f.u68.c[3].y = f.u2c.ac.D;
                f.u68.c[3].z = 0.0f;

                Node *n0c = p40->f0c;
                if (n0c) {
                ApplyGroup(n0c, &f.b13);
                if (f.u28.e > 1.0f)
                    f.u28.e = 1.0f;
                if (f.u4.f > 0.7f)
                    f.u4.f = 0.7f;
                f.arr2[0] = f.u28.e * 40.0f;
                float ff = f.u4.f;
                f.u4.ang = 1.57079637f;
                f.arr2[1] = ff * 30.0f;
                f.arr2[2] = f.u28.e * 40.0f;
                f.arr2[3] = ff * 30.0f;
                for (int i = 0; i < 4; i++) {
                    f.v = f.u68.c[i];
                    int j = (i + 1) % 4;
                    f.v.x = (f.v.x + f.u68.c[j].x) * 0.5f;
                    f.v.y = (f.v.y + f.u68.c[j].y) * 0.5f;
                    f.v.z = (f.v.z + f.u68.c[j].z) * 0.5f;
                    f.u3c.R->v24(&f.v, &f.vb4, &f.u2c.o3);
                    f.va8.x = f.u2c.o3.x - f.vb4.x;
                    f.va8.y = f.u2c.o3.y - f.vb4.y;
                    f.va8.z = f.u2c.o3.z - f.vb4.z;
                    f.va8.FUN_0022d110();
                    f.P.x = f.va8.x * 0.01f + f.vb4.x;
                    f.P.y = f.va8.y * 0.01f + f.vb4.y;
                    f.P.z = f.va8.z * 0.01f + f.vb4.z;
                    DAT_0052c2ac->dev->v15(0);
                    DAT_0052c2ac->FUN_00293d00(&f.P);
                    ((Fx *)f.self)->FUN_001bc730();
                    DAT_0052c2ac->FUN_00293c20(f.u4.ang);
                    DAT_0052c2ac->FUN_00293da0(0.004f, 0.004f, f.arr2[i] * 0.004f);
                    n0c->v8(0, 0);
                    DAT_0052c2ac->dev->v16(0);
                    f.u4.ang = f.u4.ang + 1.57079637f;
                }
                }

                Node *n04 = f.u8.p40->f04;
                f.u28.eb = n04;
                Renderer *R2;
                if (n04) {
                    ApplyGroup(n04, &f.b13);
                    f.u4.a = 0;
                    if (f.u18.o20->FUN_00029a90()) {
                        Node *n08 = f.u8.p40->f08;
                        f.u4.eb = n08;
                        if (n08)
                            ApplyGroup(n08, &f.b13);
                    }
                    Dir *g18 = f.u8.p40->f18;
                    R2 = f.u3c.R;
                    f.u18.ang2 = 0.0f;
                    V3 *cp = &f.u68.c[0];
                    int cnt = 4;
                    do {
                        R2->v24(cp, &f.va8, &f.u2c.o3);
                        f.vb4.x = f.u2c.o3.x - f.va8.x;
                        f.vb4.y = f.u2c.o3.y - f.va8.y;
                        f.vb4.z = f.u2c.o3.z - f.va8.z;
                        f.vb4.FUN_0022d110();
                        f.P.x = f.vb4.x * 0.01f + f.va8.x;
                        f.P.y = f.vb4.y * 0.01f + f.va8.y;
                        f.P.z = f.vb4.z * 0.01f + f.va8.z;
                        DAT_0052c2ac->dev->v15(0);
                        DAT_0052c2ac->FUN_00293d00(&f.P);
                        ((Fx *)f.self)->FUN_001bc730();
                        DAT_0052c2ac->FUN_00293c20(f.u18.ang2);
                        DAT_0052c2ac->FUN_00293da0(0.004f, 0.004f, 0.004f);
                        if (g18) {
                            f.v.x = -g18->x;
                            f.v.y = -g18->y;
                            f.v.z = -g18->z;
                            DAT_0052c2ac->FUN_00293d00(&f.v);
                        }
                        if (f.u4.eb)
                            f.u4.eb->v8(0, 0);
                        f.u28.eb->v8(0, 0);
                        DAT_0052c2ac->dev->v16(0);
                        f.u18.ang2 = f.u18.ang2 + 1.57079637f;
                        cp++;
                    } while (--cnt != 0);
                } else {
                    R2 = f.u3c.R;
                }

                Node *n10 = f.u8.p40->f10;
                if (n10) {
                    Group *g = n10->f48;
                    if (g) {
                        f.u8.n = g->b8;
                        f.u3c.i = 0;
                        if (g->b8 != 0) {
                            do {
                                Item *it = g->f24[g->f18[(unsigned char)f.u3c.i]];
                                if (it) {
                                    if (FUN_00344e74(it, 0, DAT_0049fd74, DAT_004c4bb4, 0)) {
                                        f.u18.arg = (it->v11() - 1.0f - 1.0f) * (1.0f - f.k);
                                        it->v12(f.u18.arg);
                                    } else if (f.b13) {
                                        it->v12(1.0f);
                                    } else {
                                        it->v12(0.0f);
                                    }
                                }
                                f.u3c.i++;
                            } while ((unsigned int)f.u3c.i < (unsigned int)f.u8.n);
                        }
                        n10->v6(0, 0);
                    }
                    f.v.x = f.u68.c[2].x;
                    f.v.y = f.u68.c[2].y;
                    f.v.z = f.u68.c[2].z;
                    f.v.x = (f.v.x + f.u68.c[3].x) * 0.5f;
                    f.v.y = (f.v.y + f.u68.c[3].y) * 0.5f;
                    f.v.z = (f.v.z + f.u68.c[3].z) * 0.5f;
                    R2->v24(&f.v, &f.va8, &f.u2c.o3);
                    f.vb4.x = f.u2c.o3.x - f.va8.x;
                    f.vb4.y = f.u2c.o3.y - f.va8.y;
                    f.vb4.z = f.u2c.o3.z - f.va8.z;
                    f.vb4.FUN_0022d110();
                    f.P.x = f.vb4.x * 0.01f + f.va8.x;
                    f.P.y = f.vb4.y * 0.01f + f.va8.y;
                    f.P.z = f.vb4.z * 0.01f + f.va8.z;
                    DAT_0052c2ac->dev->v15(0);
                    DAT_0052c2ac->FUN_00293d00(&f.P);
                    ((Fx *)f.self)->FUN_001bc730();
                    DAT_0052c2ac->FUN_00293da0(0.004f, 0.004f, 0.004f);
                    n10->v8(0, 0);
                    DAT_0052c2ac->dev->v16(0);
                }
            }
        }
    }
    DAT_0052c2a8->v62(f.u60.dw);
    DAT_0052c2a8->v60(f.prevI);
}
