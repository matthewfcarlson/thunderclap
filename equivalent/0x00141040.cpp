// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 25/26, incomplete)
// hulkfight::motion::WallJumpAction::vfunc_5 @ 0x00141040
extern "C" double sqrt(double);

struct V3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(V3 *other, float limit);
};

struct Plane {
    float x, y, z, w;
    void FUN_00037680(const V3 *n, const V3 *p);
};

struct Mat4 {
    float m[16];
    void FUN_0022be40(const V3 *pos);
    void FUN_00221d20(float angle);
};

struct Sub11c {
    char pad0[0x30];
    float f30;
    float f34;
};

struct Stats {
    char pad0[0x11c];
    Sub11c *f11c;
    char pad120[0x140 - 0x120];
    int f140;
    char pad144[0x1ad4 - 0x144];
    V3 v1ad4;
    V3 v1ae0;
    V3 v1aec;
    V3 v1af8;
    char pad1b04[0x2064 - 0x1b04];
    V3 v2064;
    void FUN_000359c0(int v);
    void FUN_000357a0(V3 *v);
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
    char pad0[0x20];
    float f20;
    char pad24[0x2c - 0x24];
    float f2c;
    char pad30[0x34 - 0x30];
    float f34;
};

double __cdecl FUN_00224f10(V3 *v);
double __cdecl FUN_00224fc0(int a, int b);
void __cdecl FUN_00224d70(int angle, V3 *v);
extern V3 DAT_004ad77c;

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

class WallJumpAction {
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
    V3 contactPos;
    V3 contactNormal;
    char hasContact;
    char pad41[3];
    V3 vel2;
};

bool WallJumpAction::vfunc_5(Slot a1, Slot a2)
{
    struct Frame {
        float s0;
        float s4;
        float s8;
        float sC;
        Clock *clk;
        V3 v0;
        V3 d;
        V3 a;
        V3 b;
        V3 vc;
        V3 p;
        V3 vcopy;
        Plane q;
    } f;

    if (a1.i != 0)
        return true;
    if (target == 0)
        return false;

    f.clk = owner->FUN_000592a0();
    Stats *st = f.clk->FUN_00059a30();
    st->FUN_000359c0(3);
    f.s0 = (float)FUN_00224f10(&vel2);
    f.vcopy = st->v2064;
    f.s4 = (float)FUN_00224f10(&f.vcopy);
    f.sC = f.s0;
    double diffA = FUN_00224fc0(*(int *)&f.s0, *(int *)&f.s4);

    double v;
    if (!(diffA < 2.3561944961547852)) {
        v = f.sC;
    } else {
        f.sC = cfg->f2c;
        if (f.sC < 0.0f) {
            v = f.s4;
        } else {
            double diff3 = FUN_00224fc0(*(int *)&f.s0, *(int *)&f.s4);
            double stepd = (double)f.sC * a2.f;
            f.sC = (float)stepd;
            f.s8 = (float)diff3;
            Bits ab;
            ab.f = f.s8;
            ab.u &= 0x7fffffff;
            f.s8 = ab.f;
            if (f.s8 <= f.sC)
                v = f.s4;
            else if (diff3 < 0.0)
                v = (double)f.s0 - f.sC;
            else
                v = (double)f.sC + f.s0;
        }
    }
    float wf = (float)(v - f.s0);
    FUN_00224d70(*(int *)&wf, &vel2);

    Cfg *c2 = cfg;
    vel2.y = (float)((double)vel2.y - a2.f * c2->f20);
    *(int *)&f.s8 = *(int *)&c2->f34;
    f.sC = (float)FUN_00224f10(&vel2);
    f.v0 = DAT_004ad77c;
    FUN_00224d70(*(int *)&f.sC, &f.v0);
    f.vc = st->v2064;
    f.vc.y = 0.0f;
    f.vc.FUN_0022d110();
    double t = (f.v0.z * f.vc.z + f.v0.x * f.vc.x + f.v0.y * f.vc.y) * f.s8;
    double h = sqrt(vel2.x * vel2.x + vel2.z * vel2.z);
    f.sC = (float)(-h);
    double tt = t;
    if (t < f.sC)
        tt = f.sC;
    double u = tt * a2.f;
    f.v0.x = (float)(f.v0.x * u);
    f.v0.y = (float)(f.v0.y * u);
    f.v0.z = (float)(f.v0.z * u);
    st->FUN_000357a0(&f.v0);

    V3 tv = vel2;
    f.p.x = 0.0f;
    f.d.x = tv.x * a2.f;
    f.d.y = tv.y * a2.f;
    f.p.y = 0.0f;
    f.p.z = 0.0f;
    f.d.z = tv.z * a2.f;
    f.clk->FUN_00059a50(&f.p);
    f.d.x = f.p.x + f.d.x;
    f.d.y = f.p.y + f.d.y;
    f.d.z = f.d.z + f.p.z;

    if (st->f140 == 4) {
        f.a = st->v1af8;
        f.b = st->v1aec;
        V3 *z = (V3 *)&f.q;
        z->x = 0.0f;
        z->y = 0.0f;
        z->z = 0.0f;
        bool take = true;
        if (!f.a.FUN_0022d2b0(z, 1e-5f)) {
        } else {
            f.a = st->v1ae0;
            f.b = st->v1ad4;
            z->x = 0.0f;
            z->y = 0.0f;
            z->z = 0.0f;
            if (f.a.FUN_0022d2b0(z, 1e-5f))
                take = false;
        }
        if (take) {
            f.a.y = 0.0f;
            f.a.FUN_0022d110();
            contactNormal = f.a;
            contactPos = f.b;
            hasContact = 1;
        }
    }

    if (hasContact) {
        double dy = f.d.y - contactPos.y;
        if (dy < st->f11c->f30) {
            f.q.FUN_00037680(&contactNormal, &contactPos);
            double dist = f.q.z * f.d.z + f.q.x * f.d.x + f.q.y * f.d.y + f.q.w;
            float R = st->f11c->f34;
            if (dist < R) {
                double k = R - dist;
                V3 n = contactNormal;
                f.a.x = (float)(n.x * k);
                f.a.y = (float)(n.y * k);
                f.a.z = (float)(n.z * k);
                st->FUN_000357a0(&f.a);
            }
        }
    }

    target->xform.FUN_0022be40(&f.d);
    float len4 = (float)FUN_00224f10(&vel2);
    target->xform.FUN_00221d20(len4);
    return true;
}
