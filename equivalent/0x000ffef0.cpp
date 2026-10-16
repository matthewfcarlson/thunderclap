// STATUS: equivalent (tools/equiv.py level 3: 927 inputs, branch coverage 122/122)
// CHand2HandAgent::vfunc_14 @ 0x000ffef0
#include "decls/address.h"
typedef unsigned __int64 u64;
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Src {
    void FUN_00059a50(V3 *out);
};

struct Ev {
    char pad0[8];
    u64 id;                        // 8
};

struct Sub231 {
    Ev *ev;
    char FUN_00231ee0();
};

struct Sec {
    char pad0[0x14];
    int f14;
};

struct Fighter {
    char pad0[8];
    u64 id;                        // 8
    Src *f10;                      // 0x10
    char pad14[0xdc - 0x14];
    Sub231 sub;                    // 0xdc
    char pade0[0x11c - 0xe0];
    Sec *f11c;
    char pad120[0x1ca8 - 0x120];
    int f1ca8;
    float f1cac;
    int f1cb0;
    int f1cb4;
    void FUN_00035550(V3 *out);
};

struct Mid {
    char pad0[8];
    Fighter *f08;
    int f0c;
    char pad10[0x40 - 0x10];
    float f40, f44, f48;
};

struct Ctrl {
    virtual void c0(); virtual void c1(); virtual void c2(); virtual void c3(); virtual void c4(); virtual void c5();
    virtual Fighter *v6();
    char pad4[0x60 - 0x4];
    Mid *f60;
    char pad64[0x9c - 0x64];
    unsigned char b9c;
    char pad9d;
    unsigned char b9e;
    char pad9f[0xa8 - 0x9f];
    int fa8, fac, fb0, fb4, fb8, fbc, fc0, fc4;
};

struct Reg {
    char pad0[0xc];
    int f0c;
    char FUN_000242d0(Fighter *t);
    char FUN_000242f0(Fighter *t);
    Fighter *FUN_00024190(int i);
};

struct Env {
    char pad0[0x20];
    Reg *f20;
};

extern V3 DAT_004a1c24;
extern u64 DAT_004dc0e0;

#define NAMEHIT(var, str) if (!var) { u64 k_ = ev->id; var = (k_ == FUN_0027b020(str)); }

struct Frame {
    Ctrl *c2;                      // S+0x10
    int count;                     // 0x14
    V3 v;                          // 0x18
};

class CHand2HandAgent {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7(); virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11(); virtual void a12(); virtual void a13();
    virtual void vfunc_14(Env *env, int unused);
    char pad04[0x58 - 0x4];
    Ctrl *f58;
    char pad5c[0x70 - 0x5c];
    float f70;
    char pad74[0x88 - 0x74];
    V3 f88;
    V3 f94;
    Mid *fa0;
    V3 fa4;
    V3 fb0;
    V3 fbc;
    float fc8;
    unsigned char bcc, bcd, bce, bcf, bd0, bd1, bd2, bd3;
    int fd4, fd8, fdc;
    float fe0;
    int fe4, fe8, fec, ff0, ff4, ff8, ffc, f100;
    char pad104[0x11c - 0x104];
    int f11c, f120;
    int f124;
    int f128;
    unsigned char b12c;
    char pad12d[3];
    float f130;
    Ev *f134;
};

void CHand2HandAgent::vfunc_14(Env *env, int unused)
{
    Frame f;
    Fighter *P = f58->v6();
    P->f10->FUN_00059a50(&f88);
    P->FUN_00035550(&f94);
    f94.y = 0.0f;
    f94.FUN_0022d110();
    Ctrl *c2 = f58;
    f.c2 = c2;
    Mid *q = c2->f60;
    fa0 = q;
    if (q->f0c == 1) {
        Fighter *t = q->f08;
        t->f10->FUN_00059a50(&fa4);
        t->FUN_00035550(&fb0);
        fb0.y = 0.0f;
        fb0.FUN_0022d110();
        bd1 = P->sub.FUN_00231ee0();
        bcf = env->f20->FUN_000242d0(t);
        bd0 = env->f20->FUN_000242f0(t);
    } else {
        fa4.x = q->f40;
        fa4.y = q->f44;
        fa4.z = q->f48;
        fb0 = DAT_004a1c24;
        bd1 = 0;
        bcf = 0;
        bd0 = 0;
    }
    bcc = c2->b9c;
    fbc.x = fa4.x - f88.x;
    fbc.y = fa4.y - f88.y;
    f.v.z = fa4.z - f88.z;
    fbc.z = f.v.z;
    fbc.y = 0.0f;
    fc8 = (float)sqrt(fbc.x * fbc.x + fbc.y * fbc.y + fbc.z * fbc.z);
    fbc.FUN_0022d110();
    bd2 = c2->b9e;
    if (f70 > 0.0f && f70 <= 2.0f)
        bd3 = 1;
    else
        bd3 = 0;
    bcd = 0;
    bce = 0;
    if (bcf != 0) {
        Ev *ev = fa0->f08->sub.ev;
        if (ev != 0) {
            bool a = false;
            NAMEHIT(a, "idle");
            NAMEHIT(a, "getup");
            NAMEHIT(a, "force_on_ground");
            NAMEHIT(a, "idle_s");
            NAMEHIT(a, "getup_s");
            NAMEHIT(a, "vert");
            NAMEHIT(a, "back_n");
            NAMEHIT(a, "flip_s");
            NAMEHIT(a, "hit_wall_ground");
            NAMEHIT(a, "hit_n");
            NAMEHIT(a, "hit_s");
            NAMEHIT(a, "hit_slide");
            NAMEHIT(a, "land_base");
            NAMEHIT(a, "knockdown_n");
            NAMEHIT(a, "knockdown_s");
            NAMEHIT(a, "knockdown_e");
            NAMEHIT(a, "knockdown_w");
            if (a)
                bcd = 1;
            bool b = false;
            NAMEHIT(b, "lockup");
            NAMEHIT(b, "struggle_base");
            NAMEHIT(b, "break");
            NAMEHIT(b, "default");
            NAMEHIT(b, "pickup");
            if (b)
                bce = 1;
        }
    }
    fd4 = P->f1cb0;
    fd8 = P->f1cb4;
    fdc = P->f1ca8;
    fe0 = P->f1cac;
    fe4 = fd4;
    fe8 = fd8;
    if (bd2 != 0) {
        fec = c2->fa8;
        ff0 = c2->fac;
        ff4 = c2->fb0;
        ff8 = c2->fb4;
        ffc = c2->fb8;
        f100 = c2->fbc;
        f11c = c2->fc0;
        f120 = c2->fc4;
    }
    f124 = 0;
    f128 = 0;
    b12c = 1;
    f130 = -1.0f;
    f.count = env->f20->f0c;
    if (f.count > 0) {
        int i;
        for (i = 0; i < f.count; i++) {
            Fighter *it = env->f20->FUN_00024190(i);
            if (it == 0)
                continue;
            if (it->id == DAT_004dc0e0)
                continue;
            if (it == P)
                continue;
            f124++;
            it->f10->FUN_00059a50(&f.v);
            double dx = f.v.x - fa4.x;
            double dy = f.v.y - fa4.y;
            double dz = f.v.z - fa4.z;
            double len1 = sqrt(dz * dz + dy * dy + dx * dx);
            if (len1 < fc8)
                b12c = 0;
            if (len1 <= fe0)
                f128++;
            double ex = f.v.x - f88.x;
            double ey = f.v.y - f88.y;
            double ez = f.v.z - f88.z;
            double len2 = sqrt(ez * ez + ey * ey + ex * ex);
            if (f130 < 0.0f || len2 < f130)
                f130 = (float)len2;
            if (it->f11c->f14 > P->f11c->f14)
                f128++;
        }
    }
    f134 = P->sub.ev;
}
