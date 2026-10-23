// STATUS: equivalent (tools/equiv.py level 3: 3016 inputs, branch coverage 20/20)
// FUN_003160f0 @ 0x003160f0
extern "C" double sqrt(double);

struct V3_3160f0 {
    float x, y, z;
};

union FloatBits_3160f0 {
    float f;
    unsigned int u;
};

struct CapB;

class BoxA_3160f0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_3160f0* v4();
    char pad04[0x48 - 4];
    float ext[3];
    V3_3160f0 axis[3];
    void FUN_002fb990(V3_3160f0* out, int axis, int sign);
};

class CapB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V3_3160f0* v4();
    char pad04[0x44 - 4];
    V3_3160f0 dir;
    float f50;
    float f54;
};

struct Frame_3160f0 {
    float scratch;
    float f4unused;
    float adp;
    float m;
    float inv;
    float s;
    int j;
    int i;
    float f54;
    float kx;
    float ky;
    float kz;
    V3_3160f0 out;
    V3_3160f0 u;
    float len;
    float q;
};

class Collider_3160f0 {
public:
    char pad00[0xc];
    float f0c;
    char pad10[4];
    V3_3160f0 d;
    void FUN_00315620(V3_3160f0* out, V3_3160f0* axis, float ext, V3_3160f0* u, V3_3160f0* b, float f50, float* kv, float L, float m, BoxA_3160f0* a, CapB* cap);
    void FUN_003160f0(BoxA_3160f0* a, CapB* b);
};

void Collider_3160f0::FUN_003160f0(BoxA_3160f0* a, CapB* b)
{
    Frame_3160f0 f;
    V3_3160f0* pa = a->v4();
    V3_3160f0* pb = b->v4();
    d.x = pb->x - pa->x;
    d.y = pb->y - pa->y;
    d.z = pb->z - pa->z;
    for (f.i = 0; f.i < 3; f.i++) {
        V3_3160f0* ax = &a->axis[f.i];
        V3_3160f0* bb = &b->dir;
        double cx = bb->z * ax->y - bb->y * ax->z;
        double cy = ax->z * bb->x - bb->z * ax->x;
        volatile float cz = bb->y * ax->x - ax->y * bb->x;
        double k = b->f50 * a->ext[f.i];
        volatile float kf = (float)k;
        f.kx = (float)(k * cx);
        f.ky = (float)(cy * kf);
        // x87: kz is stored with fst and its register copy multiplies the stored one in |k|^2
        double kzw = cz * kf;
        f.kz = (float)kzw;
        double Lx = kzw * f.kz + f.ky * f.ky + f.kx * f.kx;
        volatile float L = (float)Lx;
        if (!(Lx > 9.99999997475243e-007f))
            continue;
        double dpx = f.kz * d.z + f.ky * d.y + f.kx * d.x;
        f.adp = (float)dpx;
        FloatBits_3160f0 fb;
        fb.f = f.adp;
        fb.u &= 0x7fffffff;
        f.adp = fb.f;
        if (!(f.adp > 9.99999997475243e-007f))
            continue;
        f.f54 = b->f54;
        f.len = (float)sqrt((double)L);
        double invx = 1.0f / f.len;
        f.inv = (float)invx;
        f.s = (float)(invx * dpx);
        for (f.j = 0; f.j < 2; f.j++) {
            a->FUN_002fb990(&f.out, f.i, f.j);
            f.q = (f.out.z * f.kz + f.out.y * f.ky + f.out.x * f.kx) * f.inv;
            FloatBits_3160f0 sb;
            sb.f = f.s;
            sb.u &= 0x7fffffff;
            FloatBits_3160f0 qb;
            qb.f = f.q;
            qb.u &= 0x7fffffff;
            f.m = (float)(sb.f - (qb.f + f.f54));
            float aq = qb.f;
            double mn;
            if (aq < b->f54)
                mn = aq;
            else
                mn = b->f54;
            if (!(aq > 9.99999997475243e-007f))
                continue;
            if (!(f.m < f0c))
                continue;
            if (!(-mn < f.m))
                continue;
            if (f.q * f.s < 0.0f) {
                f.out.x = f.out.x * -1.0f;
                f.out.y = f.out.y * -1.0f;
                f.out.z = f.out.z * -1.0f;
            }
            double w = f.inv * b->f54;
            if (f.s > 0.0f)
                w = -w;
            f.u.x = (float)(f.kx * w);
            f.u.y = (float)(f.ky * w);
            f.u.z = (float)(f.kz * w);
            FUN_00315620(&f.out, &a->axis[f.i], a->ext[f.i], &f.u, bb, b->f50, &f.kx, f.len, f.m, a, b);
        }
    }
}
