// STATUS: equivalent (tools/equiv.py level 3: 706 inputs, branch coverage 9/10, incomplete)
// pure3d::ParticlePlaneGenerator::vfunc_6 @ 0x002d2630
struct Vec3 {
    float x, y, z;
    void FUN_0022d260(struct Mat4 *m);
    float FUN_0022d110();
};

struct Mat4 {
    float m[12];
    Vec3 pos;
    float w;
    void FUN_0022c3b0(const Vec3 *in, Vec3 *out);
};

struct RandState {
    unsigned int s0;
    unsigned int s1;
};

extern RandState DAT_00554bfc;

class Emitter {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual bool v14(Vec3 *dir, Vec3 *pos, float t);
};

void __cdecl FUN_00356bf0(float r, float az, float pol, float *x, float *y, float *z);

union FloatBits {
    float f;
    unsigned int u;
};

union MatArg {
    Mat4 *mat;
    float f;
    unsigned int u;
};

union EmArg {
    Emitter *em;
    float f;
};

static __forceinline unsigned int NextBits(RandState *r)
{
    r->s0 = (r->s0 & 0xffff) * 0x9069 + (r->s0 >> 16);
    r->s1 = (r->s1 & 0xffff) * 0x4650 + (r->s1 >> 16);
    return (r->s0 << 16) + (r->s1 & 0xffff);
}

static __forceinline float NextSigned(RandState *r)
{
    unsigned int x = NextBits(r);
    FloatBits b;
    b.u = (x & 0x7fffff) | 0x3f800000;
    b.f = b.f - 1.0f;
    b.u |= x & 0x80000000;
    return b.f;
}

static __forceinline float NextRaw(RandState *r)
{
    unsigned int x = NextBits(r);
    FloatBits b;
    b.u = (x & 0x7fffff) | 0x3f800000;
    return b.f;
}

class ParticlePlaneGenerator {
public:
    char pad00[0x38];
    float f38, f3c, f40;
    float f44, f48, f4c;
    float f50, f54, f58, f5c;
    unsigned int vfunc_6(unsigned int count, MatArg from, MatArg to, float step, EmArg em);
};

unsigned int ParticlePlaneGenerator::vfunc_6(unsigned int count, MatArg from, MatArg to, float step, EmArg em)
{
    if (count == 0)
        return 0;

    struct Frame {
        float t;
        unsigned int n;
        unsigned int i;
        float u3;
        float v3;
        float v2;
        float v1;
        float u5;
        float u4;
        Vec3 p;
        Vec3 r;
        Vec3 w;
        Vec3 d;
        float c60;
        float pad64;
        float c68;
        Vec3 q;
    } f;

    f.p = from.mat->pos;
    float dx = f.p.x - to.mat->pos.x;
    float dy = f.p.y - to.mat->pos.y;
    float dz = f.p.z - to.mat->pos.z;
    to.f = 1.0f / (float)count;
    f.d.x = dx * to.f;
    f.d.y = dy * to.f;
    f.d.z = dz * to.f;
    float inv = to.f;
    step = inv * step;
    f.t = 0.0f;
    f.n = 0;
    f.i = 0;
    f.v1 = f54 * f40;
    f.v2 = f58 * f44;
    f.v3 = f5c * f48;
    f.c60 = f4c * f38 * -0.5f;
    f.c68 = f50 * f3c * -0.5f;
    Mat4 *fromMat = from.mat;
    Emitter *emitter = em.em;
    do {
        float r1 = NextSigned(&DAT_00554bfc);
        float r2 = NextSigned(&DAT_00554bfc);
        f.u3 = NextRaw(&DAT_00554bfc);
        to.f = r1;
        from.f = r2;
        em.f = (f.u3 - 1.0f) * f.v3;
        FUN_00356bf0(1.0f, to.f * f.v1 + 1.5707964f, from.f * f.v2 + 1.5707964f, &f.w.x, &f.w.y, &f.w.z);
        f.w.FUN_0022d260(fromMat);
        f.w.FUN_0022d110();
        f.u4 = NextRaw(&DAT_00554bfc);
        f.u5 = NextRaw(&DAT_00554bfc);
        f.q.x = (f.u5 - 1.0f) * f38 + f.c60;
        f.q.y = 0.0f;
        f.q.z = (f.u4 - 1.0f) * f3c + f.c68;
        fromMat->FUN_0022c3b0(&f.q, &f.r);
        float ax = f.r.x + f.p.x;
        float ay = f.r.y + f.p.y;
        f.r.z = f.r.z + f.p.z;
        f.r.x = f.w.x * em.f + ax;
        f.r.y = f.w.y * em.f + ay;
        f.r.z = f.w.z * em.f + f.r.z;
        if (!emitter->v14(&f.w, &f.r, f.t))
            break;
        f.n++;
        f.i++;
        f.p.x = f.p.x + f.d.x;
        f.p.y = f.p.y + f.d.y;
        f.p.z = f.p.z + f.d.z;
        f.t = f.t + step;
    } while (f.i < count);
    return f.n;
}
