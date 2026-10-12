// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 44/44)
// hulkfight::motion::WallRunAction::vfunc_5 @ 0x0013fa80
extern "C" double cos(double);
extern "C" double sqrt(double);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110() throw();
    char FUN_0022d2b0(const Vec3 *z, float eps) throw();
    void FUN_000111b0(const Vec3 *a, const Vec3 *b) throw();
};

struct Quat {
    float q[4];
    void FUN_0022b170(float angle, Vec3 *axis) throw();
    void FUN_0022b4d0(Vec3 *in, Vec3 *out) throw();
};

struct Fighter {
    void FUN_00059a50(Vec3 *out) throw();
};

struct Stats2 {
    char pad0000[0x1ae0];
    Vec3 v1ae0;
    char pad1aec[0x1af8 - 0x1aec];
    Vec3 v1af8;
    char pad1b04[0x2008 - 0x1b04];
    float f2008;
    char pad200c[0x2064 - 0x200c];
    Vec3 v2064;
    void FUN_000359c0(int a) throw();
};

struct Obj24 {
    char pad000[0x8a0];
    float f8a0;
    float f8a4;
    char pad8a8[8];
    float f8b0;
};

struct Sub18 {
    void FUN_0022be40(Vec3 *p) throw();
    void FUN_00222180(Vec3 *p) throw();
};

struct Obj28 {
    char pad00[0x18];
    Sub18 sub;
};

struct Cfg {
    char pad00[0x1c];
    float f1c;
    float f20;
    char pad24[4];
    float f28;
    float f2c;
    float f30;
    float f34;
};

extern float DAT_004e0f78;
extern unsigned int DAT_004e0f7c;

Fighter *__fastcall FUN_000592a0(void *owner) throw();
Stats2 *__fastcall FUN_00059a30(Fighter *f) throw();
float __cdecl FUN_00224fc0(float a, float b) throw();
float __cdecl FUN_00018a20(float x) throw();
float __cdecl FUN_000186b0(float *v, float *lo, float *hi) throw();

union Arg1 {
    int i;
    float f;
    unsigned int u;
};

union Arg2 {
    float f;
    unsigned int u;
};

class WallRunAction {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual char vfunc_5(Arg1 a1, Arg2 a2);
    char pad04[0x18];
    Cfg *f1c;
    void *f20;
    Obj24 *f24;
    Obj28 *f28;
    Vec3 v2c;
    Vec3 v38;
    Vec3 v44;
    char b50;
    char pad51[3];
    float f54;
};

char WallRunAction::vfunc_5(Arg1 a1, Arg2 a2)
{
    struct Frame {
        float s0;
        Vec3 U;
        Vec3 W;
        Vec3 X;
        Vec3 Y2;
        Vec3 V;
        Vec3 P;
        Vec3 Y;
        Quat M;
    } f;

    if (a1.i != 0)
        return 1;
    if (f24 == 0 || f28 == 0)
        return 0;
    Fighter *fighter = FUN_000592a0(f20);
    Stats2 *stats = FUN_00059a30(fighter);
    f.P.x = 0.0f;
    f.P.y = 0.0f;
    f.P.z = 0.0f;
    fighter->FUN_00059a50(&f.P);
    f.U = stats->v1af8;
    bool ok = true;
    f.V.x = 0.0f;
    f.V.y = 0.0f;
    f.V.z = 0.0f;
    if (f.U.FUN_0022d2b0(&f.V, 1e-05f)) {
        f.U = stats->v1ae0;
        f.V.x = 0.0f;
        f.V.y = 0.0f;
        f.V.z = 0.0f;
        if (f.U.FUN_0022d2b0(&f.V, 1e-05f))
            ok = false;
    }
    a1.f = f.U.y;
    a1.u &= 0x7fffffff;
    if (a1.f > 0.6f)
        ok = false;
    f.U.y = 0.0f;
    f.U.FUN_0022d110();
    if (!(DAT_004e0f7c & 1)) {
        DAT_004e0f7c |= 1;
        DAT_004e0f78 = (float)cos(0.017453293005625408);
    }
    f.V.x = v2c.x;
    f.V.z = v2c.z;
    f.V.y = 0.0f;
    f.V.FUN_0022d110();
    float d1 = f.V.z * f.U.z + f.V.x * f.U.x + f.V.y * f.U.y;
    if (DAT_004e0f78 - 1.0f < d1) {
        if (f.U.z * v38.z + f.U.y * v38.y + f.U.x * v38.x < -0.707107f) {
            ok = false;
        } else {
            double c = cos(f1c->f34);
            if (c > f.U.z * v44.z + f.U.y * v44.y + f.U.x * v44.x)
                ok = false;
        }
    } else {
        v38 = f.U;
    }
    v44 = f.U;
    stats->FUN_000359c0(4);
    if (b50 == 0) {
        float diff = FUN_00224fc0(stats->f2008, f54);
        a1.f = diff;
        a1.u &= 0x7fffffff;
        if (a1.f > 0.0872665f)
            b50 = 1;
    }
    if (b50 != 0) {
        f.V = v2c;
        f.V.FUN_0022d110();
        a1.f = f.V.z * stats->v2064.z + f.V.y * stats->v2064.y + f.V.x * stats->v2064.x;
        if (a1.f < 1.0f) {
            f.Y.FUN_000111b0(&f.V, &stats->v2064);
            f.Y.FUN_0022d110();
            double ang = FUN_00018a20(a1.f);
            double maxStep = a2.f * f1c->f30;
            a1.f = (float)maxStep;
            if (maxStep > ang)
                a1.f = (float)ang;
            f.M.FUN_0022b170(a1.f, &f.Y);
            f.M.FUN_0022b4d0(&v2c, &v2c);
        }
    }
    v2c.y = v2c.y - a2.f * f1c->f28;
    a1.f = (float)sqrt(v2c.x * v2c.x + v2c.y * v2c.y + v2c.z * v2c.z);
    double nd = -(f.U.z * v2c.z + f.U.y * v2c.y + f.U.x * v2c.x);
    v2c.x = f.U.x * nd + v2c.x;
    v2c.y = f.U.y * nd + v2c.y;
    v2c.z = f.U.z * nd + v2c.z;
    v2c.FUN_0022d110();
    v2c.x = a1.f * v2c.x;
    v2c.y = a1.f * v2c.y;
    v2c.z = a1.f * v2c.z;
    f.W = v2c;
    double len = f.W.FUN_0022d110();
    if (len <= 0.0f) {
        f.W.x = 0.0f;
        f.W.y = 1.0f;
        f.W.z = 0.0f;
    }
    double lo = f1c->f1c;
    a1.f = (float)(len - a2.f * f1c->f2c);
    if (f1c->f1c < 0.0f)
        lo = 0.0f;
    if (a1.f < lo)
        a1.f = (float)lo;
    f.s0 = f1c->f20;
    if (f1c->f20 > lo && a1.f > f.s0)
        a1.f = f.s0;
    v2c = f.W;
    v2c.x = a1.f * v2c.x;
    v2c.y = a1.f * v2c.y;
    v2c.z = a1.f * v2c.z;
    f.X = v2c;
    f.X.x = f.X.x * a2.f;
    f.X.y = f.X.y * a2.f;
    f.X.z = f.X.z * a2.f;
    f.X.x = f.X.x + f.P.x;
    f.X.y = f.X.y + f.P.y;
    f.X.z = f.X.z + f.P.z;
    f28->sub.FUN_0022be40(&f.X);
    f.Y2.x = f.U.x * -1.0f;
    f.Y2.y = 0.0f;
    f.Y2.z = f.U.z * -1.0f;
    if (f.Y2.FUN_0022d110() > 0.0f)
        f28->sub.FUN_00222180(&f.Y2);
    f24->f8b0 = a1.f;
    f.P.x = f.W.y * 0.0f - f.W.z;
    a2.u = *(unsigned int *)&f.W.y;
    f.P.y = f.W.z * 0.0f - f.W.x * 0.0f;
    f.s0 = -0.9999f;
    a1.u = 0x3f7ff972;
    f.P.z = f.W.x - f.W.y * 0.0f;
    a2.f = FUN_000186b0(&a2.f, &f.s0, &a1.f);
    float angle = FUN_00018a20(a2.f);
    if (f.P.z * f.U.z + f.P.x * f.U.x + f.P.y * f.U.y < 0.0f)
        angle = -angle;
    f24->f8a0 = angle;
    f24->f8a4 = 1.0f;
    return ok;
}
