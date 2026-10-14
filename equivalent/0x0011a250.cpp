// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 54/56, incomplete)
// hulkfight::ai::MotionClosestWaypointAction::vfunc_5 @ 0x0011a250
extern "C" double sqrt(double);

struct Vec3_11a250 {
    float x, y, z;
    float FUN_0022d110() throw();
};

struct Fighter_11a250 {
    void FUN_00059a50(Vec3_11a250 *out) throw();
};

struct Cfg2 {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    char b28;
    char pad29[3];
    float f2c;
    float f30;
};

struct Ent_11a250 {
    char pad00[0x10];
    Fighter_11a250 *f10;
};

struct Hand_11a250 {
    char pad00[0x129];
    char b129;
};

class Sink_11a250 {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4(Vec3_11a250 *a, Vec3_11a250 *b, struct Stats_11a250 *s, struct World *w, float dt, Vec3_11a250 *c, Vec3_11a250 *d) throw();
};

struct Stats_11a250 {
    char pad000[0x10];
    Ent_11a250 *f10dummy;
};

struct Agent;
struct World;

struct Stats2_11a250 {
    char pad000[0x10];
    Fighter_11a250 *f10;
    char pad014[0x1ca0 - 0x14];
    Hand_11a250 *f1ca0;
    Sink_11a250 *f1ca4;
    char pad1ca8[0x2064 - 0x1ca8];
    float f2064, f2068, f206c, f2070;
    void FUN_00036e70(Vec3_11a250 *p, int flag) throw();
};

Ent_11a250 *__fastcall FUN_000592a0(void *owner) throw();
Stats2_11a250 *__fastcall FUN_00059a30(Ent_11a250 *e) throw();
float __cdecl FUN_0010b1c0(World *w, Stats2_11a250 *s, float thr, Vec3_11a250 *out) throw();
float __cdecl FUN_000186f0(float *a, float *b) throw();
extern World *DAT_004dd700;

struct Misc {
    void FUN_000344b0(float x) throw();
};

union Arg1_11a250 {
    int i;
    float f;
};

class MotionClosestWaypointAction {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual bool vfunc_5(Arg1_11a250 a1, float dt);
    char pad04[0x18];
    Cfg2 *f1c;
    void *f20;
    Vec3_11a250 v24;
    float f30;
    float f34;
    float f38;
    Vec3_11a250 v3c;
    char pad48[4];
    Vec3_11a250 v4c;
    char pad58[4];
    float f5c;
    float v60[2];
    char FUN_00117da0() throw();
};

bool MotionClosestWaypointAction::vfunc_5(Arg1_11a250 a1, float dt)
{
    struct Frame {
        float rmin;
        float w;
        float rmax;
        float N;
        Vec3_11a250 U;
        Vec3_11a250 P;
        Vec3_11a250 Dv;
        Vec3_11a250 W;
        Vec3_11a250 Q;
    } f;

    if (a1.i != 0)
        return true;
    if (f20 == 0)
        return false;
    Stats2_11a250 *edi = FUN_00059a30(FUN_000592a0(f20));
    f.P.x = 0.0f;
    f.P.y = 0.0f;
    f.P.z = 0.0f;
    edi->f10->FUN_00059a50(&f.P);
    f.Dv.y = 0.0f;
    f.Dv.x = v3c.x - f.P.x;
    f.Dv.z = v3c.z - f.P.z;
    f.N = -(v3c.y - f.P.y);
    float len = f.Dv.FUN_0022d110();
    a1.f = len;
    f38 = f.N;
    f34 = a1.f;
    f.U.x = 0.0f;
    f.U.y = 0.0f;
    f.U.z = 0.0f;
    Cfg2 *c = f1c;
    f.w = 0.0f;
    f.rmin = c->f18;
    f.rmax = c->f1c;
    if (a1.f < f.rmin) {
        f.U.x = f.Dv.x * -1.0f;
        f.U.y = f.Dv.y * -1.0f;
        f.U.z = f.Dv.z * -1.0f;
        f.w = c->f14;
    } else if (a1.f > f.rmax) {
        f.U = f.Dv;
        f.w = c->f14;
    }
    if (f.N < c->f20) {
        if (a1.f >= f.rmin && a1.f <= f.rmax) {
            f.U.y = 1.0f;
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else if (a1.f < f.rmin && f.rmin > 0.0f) {
            f.U.y = 1.0f - (f.rmin - a1.f) / f.rmin;
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else if (a1.f > f.rmax && a1.f < f.rmax + f.rmax && f.rmax > 0.0f) {
            f.U.y = (f.rmax + f.rmax - a1.f) / (f.rmax + f.rmax);
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else {
            f.U.y = 0.0f;
        }
    } else if (f.N > c->f24) {
        if (a1.f >= f.rmin && a1.f <= f.rmax) {
            f.U.y = -1.0f;
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else if (a1.f < f.rmin && f.rmin > 0.0f) {
            f.U.y = (f.rmin - a1.f) / f.rmin - 1.0f;
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else if (a1.f > f.rmax && a1.f < f.rmax + f.rmax && f.rmax > 0.0f) {
            f.U.y = -((f.rmax + f.rmax - a1.f) / (f.rmax + f.rmax));
            f.U.FUN_0022d110();
            f.w = f1c->f14;
        } else {
            f.U.y = 0.0f;
        }
    }
    edi->f2064 = f.U.x;
    edi->f2068 = f.U.y;
    edi->f206c = f.U.z;
    edi->f2070 = f.w;
    if (f1c->b28 != 0 && edi->f1ca0 != 0 && edi->f1ca4 != 0) {
        f.Q.x = f.P.x;
        f.Q.y = f.P.y + 1.0f;
        f.Q.z = f.P.z;
        f.W.x = 0.0f;
        f.W.y = 0.0f;
        f.W.z = 0.0f;
        a1.f = 1.5f;
        if (edi->f1ca0->b129 == 0)
            a1.f = 0.75f;
        f.N = FUN_0010b1c0(DAT_004dd700, edi, a1.f, &f.W);
        if (f.N < 0.0f || f.N > a1.f) {
            edi->f1ca0->b129 = 0;
            f.W.z = 0.0f;
            f.W.y = 0.0f;
            f.W.x = 0.0f;
        } else {
            edi->f1ca0->b129 = 1;
            f.W.FUN_0022d110();
            a1.f = (a1.f - f.N) / a1.f;
            f.N = 1.0f;
            float r = FUN_000186f0(&f.N, &a1.f);
            ((Misc *)&f.W.y)->FUN_000344b0(r);
        }
        edi->f1ca4->v4(&v3c, &f.Q, (Stats_11a250 *)edi, DAT_004dd700, dt, &v4c, &f.W);
    }
    f30 = f.w;
    double dx = f.P.x - v24.x;
    double dy = f.P.y - v24.y;
    double dz = f.P.z - v24.z;
    a1.f = (float)sqrt(dz * dz + dy * dy + dx * dx);
    *(unsigned int *)&a1.f &= 0x7fffffff;
    Cfg2 *c2 = f1c;
    if (a1.f / dt <= c2->f30)
        f5c = dt + f5c;
    else
        f5c = 0.0f;
    edi->FUN_00036e70((Vec3_11a250 *)v60, f5c > c2->f2c);
    v24 = f.P;
    return !FUN_00117da0();
}
