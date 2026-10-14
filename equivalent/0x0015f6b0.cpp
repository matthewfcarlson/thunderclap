// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 121/122, incomplete)
// hulkfight::motion::HeliLocomotionAction::vfunc_5 @ 0x0015f6b0
extern "C" double sqrt(double);
extern "C" int atexit(void (*)());
void FUN_00363f60();

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
    bool FUN_0022d2b0(const Vec3 *other, float eps);
    void FUN_0022d240(const Vec3 *in, struct Matrix *m);
    void FUN_0022d290(const Vec3 *in, struct Matrix *m);
};

struct Matrix {
    float m[16];
};

struct Quat {
    float x, y, z, w;
    void FUN_0022b170(float angle, Vec3 *axis);
    void FUN_0022b1c0(float angle);
};

struct Key {
    unsigned lo;
    unsigned hi;
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
};

extern Key DAT_004e11c8;
extern unsigned DAT_004e11d0;

float __cdecl FUN_00224ea0(float x, float z);
float __cdecl FUN_00224fc0(float a, float b);
float __cdecl FUN_00083d90(float *v);
void __cdecl FUN_0022b080(Quat *out, Quat *a, Quat *b);
char __cdecl FUN_002027c0(Vec3 *a, Vec3 *b, int c, int d, Vec3 *hitPos, Vec3 *hitNormal, int e, int f);

struct Xform {
    Matrix *FUN_00221c40();
    void FUN_00221cf0(Quat *q);
    void FUN_0022be40(Vec3 *pos);
};

struct Driver {
    char pad00[0x18];
    Xform xform;
};

struct Anchor {
    void FUN_00059a50(Vec3 *out);
};

struct Ctx {
    char pad00[0x10];
    Anchor *anchor;
    void FUN_001d69f0(Vec3 *out);
};

struct Goal {
    char pad00[8];
    Ctx *ctx;
    int kind;
    char pad10[0x30];
    Vec3 pos;
};

struct Entity {
    char pad000[0x1cc];
    Vec3 vel;
    Vec3 push;
    char pad1e4[0x328 - 0x1e4];
    Goal *goal;
    char goalActive;
    char pad32d[0x1ca0 - 0x32d];
    struct Part *part;
    char pad1ca4[0x1f6c - 0x1ca4];
    float hiA;
    char pad1f70[0x1f84 - 0x1f70];
    float hiB;
    char pad1f88[0x2064 - 0x1f88];
    Vec3 up;
    float upLimit;
    Vec3 alt1;
    Vec3 alt2;
    char pad208c[0x20a8 - 0x208c];
    int mode;
    char pad20ac[0x2149 - 0x20ac];
    char flagA;
    char pad214a[0x22b0 - 0x214a];
    char flagB;

    void FUN_000359c0(int v);
    void FUN_00035660(Vec3 *out);
    void FUN_00035550(Vec3 *out);
    void FUN_000357e0();
    void FUN_00036e70(Key *key, int on);
};

struct Part {
    char pad00[0xe8];
    char disabled;
};

struct Holder {
    Entity *FUN_00059a30();
    void FUN_00059a50(Vec3 *out);
};

struct HolderSource {
    Holder *FUN_000592a0();
};

struct Settings {
    char pad00[0x14];
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
    float f30;
    float f34;
    float f38;
    float f3c;
    Vec3 v40;
    float f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    float f64;
    char pad68[0x98 - 0x68];
    float f98;
    char pad9c[0xa8 - 0x9c];
    float fa8;
    char pada4[0xbc - 0xac];
    float fbc;
    float fc0;
    float fc4;
    float fc8;
    Vec3 vcc;
};

static __forceinline float FAbs(float v)
{
    union {
        float f;
        unsigned u;
    } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

static __forceinline bool NearZero(Vec3 *v)
{
    Vec3 z;
    z.x = 0.0f;
    z.y = 0.0f;
    z.z = 0.0f;
    return v->FUN_0022d2b0(&z, 1e-5f);
}

namespace hulkfight {
namespace motion {

class HeliLocomotionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, float dt);
    char pad04[0x18];
    Settings *volatile settings;
    HolderSource *owner;
    Driver *driver;
    float value;
    float angle;
    Vec3 p30;
    Vec3 lo;
    Vec3 hi;
    float f54;
    float f58;
    float f5c;
    float f60;
    float f64;
};

template <int K>
static __forceinline void ClampSpeed(HeliLocomotionAction *h, float s30)
{
    Settings *S = h->settings;
    if (h->f58 < S->f2c) {
        h->f58 = S->f2c;
        h->f5c = 0.0f;
    } else if ((K ? s30 + S->fc0 : s30) < h->f58) {
        h->f58 = K ? s30 + S->fc0 : s30;
        h->f5c = 0.0f;
    }
}

bool HeliLocomotionAction::vfunc_5(int a, float dt)
{
    if (driver == 0)
        return false;
    bool bl = false;
    Holder *holder = owner->FUN_000592a0();
    Entity *ent = holder->FUN_00059a30();
    ent->FUN_000359c0(3);
    Vec3 pos;
    holder->FUN_00059a50(&pos);

    if (!NearZero(&ent->push)) {
        Vec3 v;
        ent->FUN_00035660(&v);
        v.x = v.x - p30.x;
        v.y = v.y - p30.y;
        v.z = v.z - p30.z;
        v.x = v.x + ent->push.x;
        v.y = v.y + ent->push.y;
        v.z = v.z + ent->push.z;
        p30.x = v.x + p30.x;
        p30.y = v.y + p30.y;
        p30.z = v.z + p30.z;
        Vec3 fwd;
        ent->FUN_00035550(&fwd);
        fwd.y = 0.0f;
        fwd.FUN_0022d110();
        Vec3 d = v;
        d.y = 0.0f;
        float len = d.FUN_0022d110();
        float sign = -1.0f;
        if (!(d.z * fwd.z + d.y * fwd.y + d.x * fwd.x < 0.0f))
            sign = 1.0f;
        Vec3 vel = ent->vel;
        float spd = (float)sqrt(vel.x * vel.x + vel.z * vel.z);
        float t = 0.0f;
        if (spd > 0.0f)
            t = (sign / spd) * len;
        if (len > 0.0f) {
            if (t > 0.0f) {
                if (t < 0.78539818525314331f)
                    t = 0.78539818525314331f;
                else if (t > 6.2831854820251465f)
                    t = 6.2831854820251465f;
            } else {
                if (t > -0.78539818525314331f)
                    t = -0.78539818525314331f;
                else if (t < -6.2831854820251465f)
                    t = -6.2831854820251465f;
            }
        }
        angle = t + angle;
        ent->FUN_000357e0();
    }

    Vec3 dir;
    Goal *goal = ent->goal;
    if (goal != 0 && ent->goalActive != 0) {
        Vec3 w;
        if (goal->kind == 1) {
            w.x = 0.0f;
            w.y = 0.0f;
            w.z = 0.0f;
            goal->ctx->anchor->FUN_00059a50(&w);
        } else if (goal->kind == 5) {
            goal->ctx->FUN_001d69f0(&w);
        } else {
            w = goal->pos;
        }
        dir.x = w.x - pos.x;
        dir.y = w.y - pos.y;
        dir.z = w.z - pos.z;
    } else {
        dir = ent->alt1;
        if (NearZero(&dir)) {
            dir = ent->alt2;
            if (NearZero(&dir)) {
                dir = ent->up;
                if (NearZero(&dir))
                    ent->FUN_00035550(&dir);
            }
        }
        dir.FUN_0022d110();
    }

    float ang = FUN_00224ea0(dir.x, dir.z);
    float val = value;
    float r = (FUN_00224fc0(val, ang) * 0.31830987334251404f) * settings->f1c;
    float k1c = settings->f1c;
    float lim = settings->f20;
    if (lim > 0.0f) {
        float am = FAbs(angle);
        float mn = am < lim ? am : lim;
        r = r - ((((FUN_00083d90(&angle) * mn) / lim) * k1c));
    }
    angle = r * dt + angle;
    Vec3 steer = ent->up;
    val = angle * dt + val;
    float up70 = ent->upLimit;
    if (ent->mode >= 0 && ent->mode < 4) {
        float diff = ent->hiA - ent->hiB;
        float ad = FAbs(diff);
        if (ad > up70)
            up70 = ad;
        steer.y = steer.y + diff;
        steer.FUN_0022d110();
    }
    Vec3 v90;
    float f98 = settings->f98;
    ent->FUN_00035550(&v90);
    if (f98 != 0.0f) {
        Vec3 start = pos;
        Vec3 n = v90;
        Vec3 raw = v90;
        n.FUN_0022d110();
        Vec3 end;
        end.x = start.x + raw.x * settings->fa8;
        end.y = start.y;
        end.z = start.z + raw.z * settings->fa8;
        Vec3 hit;
        Vec3 hitN;
        if (FUN_002027c0(&start, &end, 0, 0, &hit, &hitN, 0, 0)) {
            float hx = hit.x - start.x;
            float hy = hit.y - start.y;
            float hz = hit.z - start.z;
            steer.y = ((1.0f / (sqrt(hx * hx + hz * hz + hy * hy) * sqrt(hx * hx + hz * hz + hy * hy))) * f98) + steer.y;
            steer.FUN_0022d110();
            bl = true;
        }
    }

    if ((DAT_004e11d0 & 1) == 0) {
        DAT_004e11d0 |= 1;
        DAT_004e11c8.FUN_0027af00();
        atexit(FUN_00363f60);
    }
    DAT_004e11c8.FUN_0027b040("flying_avoiding_wall");
    ent->FUN_00036e70(&DAT_004e11c8, 0);

    if (ent->flagA != 0 || ent->flagB == 0 || (ent->part != 0 && ent->part->disabled == 0)) {
        float au = FAbs(up70);
        if (!(au <= 1e-5f)) {
            Vec3 n;
            n.x = p30.x;
            n.y = 0.0f;
            n.z = p30.z;
            float nl = n.FUN_0022d110();
            float anl = FAbs(nl);
            if (!(anl <= 0.0099999997764825821f)) {
                Vec3 u;
                u.x = 0.0f;
                u.y = 0.0f;
                u.z = 0.0f;
                ent->FUN_00035660(&u);
                float inv = 1.0f / nl;
                u.x = u.x * inv;
                u.y = 0.0f * inv;
                u.z = u.z * inv;
                steer.y = (1.0f - (u.x * n.x + u.y * n.y + n.z * u.z)) + steer.y;
                steer.FUN_0022d110();
                ent->FUN_00036e70(&DAT_004e11c8, 1);
            }
        }
    }

    {
        float au = FAbs(up70);
        if (au <= 1e-5f)
            steer = dir;
    }

    float w;
    float s18 = settings->f18;
    if (s18 > 0.0f)
        w = s18 * up70;
    else
        w = 0.0f;
    Vec3 want;
    want.x = steer.x * w;
    want.y = steer.y * w;
    want.z = steer.z * w;
    Vec3 nv = p30;
    float u14 = settings->f14;
    if (u14 <= 0.0f) {
        nv.x = want.x;
        nv.y = want.y;
        nv.z = want.z;
    } else {
        Vec3 dd = want;
        dd.x = dd.x - nv.x;
        dd.y = dd.y - nv.y;
        dd.z = dd.z - nv.z;
        float step = u14 * dt;
        float dl = dd.FUN_0022d110();
        if (dl <= step) {
            nv.x = want.x;
            nv.y = want.y;
            nv.z = want.z;
        } else {
            nv.x = dd.x * step + nv.x;
            nv.y = dd.y * step + nv.y;
            nv.z = dd.z * step + nv.z;
        }
    }
    Vec3 w2;
    w2.x = nv.x - p30.x;
    w2.y = nv.y;
    w2.z = nv.z - p30.z;
    p30.x = nv.x;
    p30.y = nv.y;
    p30.z = nv.z;

    Vec3 np;
    np.x = p30.x * dt;
    np.y = p30.y * dt;
    np.z = p30.z * dt;
    np.x = np.x + pos.x;
    np.y = np.y + pos.y;
    np.z = np.z + pos.z;
    if (lo.x != 0.0f && np.x < lo.x)
        np.x = lo.x;
    if (lo.y != 0.0f && np.y < lo.y)
        np.y = lo.y;
    if (lo.z != 0.0f && np.z < lo.z)
        np.z = lo.z;
    if (hi.x != 0.0f && np.x > hi.x)
        np.x = hi.x;
    if (hi.y != 0.0f && np.y > hi.y)
        np.y = hi.y;
    if (hi.z != 0.0f && np.z > hi.z)
        np.z = hi.z;

    Matrix *T = driver->xform.FUN_00221c40();
    Vec3 axis = settings->v40;
    Vec3 pt;
    pt.FUN_0022d240(&axis, T);
    Vec3 dv;
    dv.x = pt.x - T->m[12];
    dv.y = pt.y - T->m[13];
    dv.z = pt.z - T->m[14];
    axis.x = 1.0f;
    axis.y = 0.0f;
    axis.z = 0.0f;
    Vec3 c;
    c.x = 0.0f * dv.z - dv.y * w2.z;
    c.y = w2.z * dv.x - dv.z * w2.x;
    c.z = dv.y * w2.x - dv.x * 0.0f;
    Vec3 ex;
    ex.FUN_0022d290(&axis, T);
    float inv18 = 1.0f / s18;
    Vec3 lim44 = settings->vcc;
    volatile float accel = ((((((((((sqrt(p30.x * p30.x + p30.y * p30.y + p30.z * p30.z) * (settings->f28 - settings->f24)) * inv18) + settings->f24) - f58) * settings->f38) + (-(settings->f3c * f5c))) / settings->f34) + (ex.x * c.x)) + (ex.z * c.z)) + (ex.y * c.y));
    float ax = v90.x - steer.x;
    float adx = FAbs(ax);
    float ay = v90.y - steer.y;
    float ady = FAbs(ay);
    float az = v90.z - steer.z;
    float adz = FAbs(az);
    if (bl) {
        if (adx > lim44.x || ady > lim44.y || adz > lim44.z)
            bl = false;
    }
    float s30 = settings->f30;
    if (bl && (nv.x != 0.0f || nv.y != 0.0f || nv.z != 0.0f)) {
        f58 = dt * f5c + f58;
        f5c = (dt * settings->fbc) + ((accel * dt) + f5c);
        f54 = dt * settings->fbc;
        ClampSpeed<1>(this, s30);
    } else {
        f58 = dt * f5c + f58;
        if (f54 > 0.0f) {
            f5c = ((accel * dt) + f5c) + f54;
            f54 = (1.0f / settings->fc4) * f54;
            if (f54 < settings->fc8)
                f54 = 0.0f;
            ClampSpeed<1>(this, s30);
        } else {
            f5c = (accel * dt) + f5c;
            ClampSpeed<0>(this, s30);
        }
    }
    Vec3 fwd2;
    axis.x = 0.0f;
    axis.y = 0.0f;
    axis.z = 1.0f;
    fwd2.FUN_0022d290(&axis, T);
    double accel2 = ((((((((((sqrt(p30.x * p30.x + p30.y * p30.y + p30.z * p30.z) * (settings->f50 - settings->f4c)) * inv18) + settings->f4c) - f60) * settings->f60) + (-(settings->f64 * f64))) / settings->f5c) + (fwd2.x * c.x)) + (fwd2.z * c.z)) + (fwd2.y * c.y));
    f60 = dt * f64 + f60;
    f64 = accel2 * dt + f64;
    if (f60 < settings->f54) {
        f60 = settings->f54;
        f64 = 0.0f;
    } else if (f60 > settings->f58) {
        f60 = settings->f58;
        f64 = 0.0f;
    }
    Quat qA;
    qA.FUN_0022b170(f58, &ex);
    Quat qB;
    qB.FUN_0022b170(f60, &fwd2);
    Quat qC;
    qC.FUN_0022b1c0(val);
    value = val;
    Quat qOut;
    FUN_0022b080(&qOut, &qA, &qB);
    FUN_0022b080(&qOut, &qOut, &qC);
    driver->xform.FUN_00221cf0(&qOut);
    driver->xform.FUN_0022be40(&np);
    return true;
}

} // namespace motion
} // namespace hulkfight
