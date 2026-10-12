// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 36/36)
// hulkfight::motion::FallAction::vfunc_5 @ 0x00134ee0
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(V3 *other, float limit);
};

struct Mat4 {
    float m[16];
    void FUN_0022be40(const V3 *pos);
    void FUN_00221d20(float angle);
};

struct Stats {
    char pad0[0x11c];
    struct Sub11c *f11c;
    char pad120[0x140 - 0x120];
    int f140;
    char pad144[0x1ae0 - 0x144];
    V3 v1ae0;
    char pad1aec[0x1af8 - 0x1aec];
    V3 v1af8;
    char pad1b04[0x2064 - 0x1b04];
    float f2064;
    char pad2068[4];
    float f206c;
    float f2070;
    void FUN_000359c0(int v);
    float FUN_000354c0();
    char FUN_00035550(V3 *out);
    void FUN_000357a0(V3 *v);
};

struct Sub11c {
    char pad0[0x34];
    float f34;
};

struct Clock {
    Stats *FUN_00059a30();
    char FUN_00059a50(V3 *out);
};

struct OwnerObj {
    Clock *FUN_000592a0();
};

struct Driver {
    char pad0[0x18];
    Mat4 xform;
};

struct Cfg {
    char pad0[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    char pad24[0x34 - 0x24];
    float f34;
    float f38;
    char b3c;
};

double __cdecl FUN_00224ea0(int x, int z);
double __cdecl FUN_00224fc0(int a, int b);
double __cdecl FUN_00224f10(V3 *v);
double __cdecl FUN_000963c0(int a, int b, int c, int d, int e);
void __cdecl FUN_00224d70(int angle, V3 *v);
extern V3 DAT_004abf64;

union Slot {
    int i;
    float f;
    unsigned int u;
};

union Bits {
    float f;
    unsigned int u;
    int i;
};

class FallAction {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual bool vfunc_5(Slot a1, Slot a2);
    char pad04[0x1c - 4];
    Cfg *cfg;
    OwnerObj *owner;
    Driver *target;
    float f28;
    float f2c;
    float f30;
};

bool FallAction::vfunc_5(Slot a1, Slot a2)
{
    struct Frame {
        float s0;
        float s4;
        float s8;
        float sC;
        float s10;
        float s14;
        float s18;
        Clock *clk;
        V3 v0;
        V3 d;
        V3 p;
        V3 vc;
    } f;

    if (a1.i != 0)
        return true;
    if (target == 0)
        return false;

    f.clk = owner->FUN_000592a0();
    Stats *st = f.clk->FUN_00059a30();
    st->FUN_000359c0(3);
    a1.f = st->FUN_000354c0();

    V3 *vel = (V3 *)&f28;
    if (st->f2070 > 0.0f) {
        double L = sqrt(vel->x * vel->x + vel->z * vel->z);
        f.s10 = (float)L;
        f.s4 = (float)FUN_00224ea0(*(int *)&st->f2064, *(int *)&st->f206c);
        f.v0 = DAT_004abf64;
        FUN_00224d70(a1.i, &f.v0);
        f.vc = *vel;
        Cfg *c = cfg;
        f.sC = c->f1c;
        f.s14 = c->f18;
        double dot2 = f.v0.z * f.vc.z + f.v0.x * f.vc.x + f.v0.y * 0.0f;
        f.s18 = (float)dot2;
        f.s8 = (float)FUN_000963c0(*(int *)&c->f18, *(int *)&c->f14, *(int *)&c->f20, *(int *)&f.sC,
                                   *(int *)&f.s10);
        f.s0 = (float)FUN_00224fc0(a1.i, *(int *)&f.s4);
        Bits ab;
        ab.f = f.s0;
        ab.u &= 0x7fffffff;
        f.s0 = ab.f;

        bool skip = false;
        if (!(f.s0 < 2.670353889465332f)) {
            if (!(f.s18 <= 10.0f)) {
                if (cfg->b3c)
                    skip = true;
            }
        }
        if (!skip) {
            int heading;
            if (f.s8 < 0.0f) {
                heading = *(int *)&f.s4;
                a1.i = heading;
            } else {
                double diff2 = FUN_00224fc0(a1.i, *(int *)&f.s4);
                double stepd = (double)f.s8 * a2.f;
                f.sC = (float)stepd;
                f.s0 = (float)diff2;
                Bits ad;
                ad.f = f.s0;
                ad.u &= 0x7fffffff;
                f.s0 = ad.f;
                if (f.s0 <= f.sC) {
                    a1.i = *(int *)&f.s4;
                } else if (diff2 < 0.0) {
                    a1.f = (float)((double)a1.f - f.sC);
                } else {
                    a1.f = (float)((double)f.sC + a1.f);
                }
            }
            f.s0 = (float)FUN_00224f10(vel);
            double res = FUN_00224fc0(*(int *)&f.s0, *(int *)&f.s4);
            f.s14 = (float)res;
            f.s18 = (float)res;
            Bits ar;
            ar.f = f.s18;
            ar.u &= 0x7fffffff;
            f.s18 = ar.f;
            if (f.s8 < 0.0f) {
                *(int *)&f.s0 = *(int *)&f.s4;
            } else {
                double step2 = (double)f.s8 * a2.f;
                if (f.s18 <= step2) {
                    *(int *)&f.s0 = *(int *)&f.s4;
                } else if (f.s14 < 0.0f) {
                    f.s0 = (float)((double)f.s0 - step2);
                } else {
                    f.s0 = (float)(step2 + f.s0);
                }
            }
            vel->y = f2c;
            vel->x = 0.0f;
            vel->z = -f.s10;
            FUN_00224d70(*(int *)&f.s0, vel);
        }
    }

    target->xform.FUN_00221d20(a1.f);
    Cfg *c3 = cfg;
    double nf = (double)f2c - a2.f * c3->f34;
    f2c = (float)nf;
    float m;
    if (c3->f38 <= 0.0f)
        m = 200.0f;
    else if (c3->f38 > 200.0f)
        m = 200.0f;
    else
        m = c3->f38;
    a1.f = -m;
    if (nf < a1.f)
        f2c = a1.f;

    V3 tv = *vel;
    f.d.x = tv.x * a2.f;
    f.d.y = tv.y * a2.f;
    f.d.z = tv.z * a2.f;

    if (st->f140 == 4) {
        f.v0 = st->v1af8;
        f.vc.x = 0.0f;
        f.vc.y = 0.0f;
        f.vc.z = 0.0f;
        if (f.v0.FUN_0022d2b0(&f.vc, 1e-5f)) {
            f.v0 = st->v1ae0;
            f.vc.x = 0.0f;
            f.vc.y = 0.0f;
            f.vc.z = 0.0f;
            if (f.v0.FUN_0022d2b0(&f.vc, 1e-5f)) {
                st->FUN_00035550(&f.v0);
                f.v0.x = f.v0.x * -1.0f;
                f.v0.z = f.v0.z * -1.0f;
            }
        }
        f.v0.y = 0.0f;
        f.v0.FUN_0022d110();
        float mm = st->f11c->f34;
        f.v0.x = f.v0.x * mm;
        f.v0.y = f.v0.y * mm;
        f.v0.z = f.v0.z * mm;
        st->FUN_000357a0(&f.v0);
    }

    f.p.x = 0.0f;
    f.p.y = 0.0f;
    f.p.z = 0.0f;
    f.clk->FUN_00059a50(&f.p);
    f.d.x = f.p.x + f.d.x;
    f.d.y = f.p.y + f.d.y;
    f.d.z = f.p.z + f.d.z;
    target->xform.FUN_0022be40(&f.d);
    return true;
}
