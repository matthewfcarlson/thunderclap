// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 9/10, incomplete)
// pure3d::ParticlePointGenerator::vfunc_6 @ 0x002d21c0
struct Vec3_2d21c0 {
    float x, y, z;
    void FUN_0022d260(struct Mat4_2d21c0* m);
    float FUN_0022d110();
};

struct Mat4_2d21c0 {
    float m[12];
    Vec3_2d21c0 pos;
    float w;
};

struct RngState {
    unsigned int a;
    unsigned int b;
};

extern RngState DAT_00554bfc;

union FloatBits_2d21c0 {
    float f;
    unsigned int u;
};

class Emitter_2d21c0 {
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
    virtual bool v14(Vec3_2d21c0* dir, Vec3_2d21c0* pos, float t);
};

void __cdecl FUN_00356bf0(float r, float az, float pol, float* x, float* y, float* z);

static unsigned int NextRandom()
{
    DAT_00554bfc.a = (DAT_00554bfc.a & 0xffff) * 0x9069 + (DAT_00554bfc.a >> 16);
    DAT_00554bfc.b = (DAT_00554bfc.b & 0xffff) * 0x4650 + (DAT_00554bfc.b >> 16);
    return (DAT_00554bfc.a << 16) + (DAT_00554bfc.b & 0xffff);
}

static float RandomSigned()
{
    unsigned int r = NextRandom();
    FloatBits_2d21c0 u;
    u.u = (r & 0x7fffff) | 0x3f800000;
    u.f = u.f - 1.0f;
    u.u |= r & 0x80000000;
    return u.f;
}

static float RandomUnsigned()
{
    unsigned int r = NextRandom();
    FloatBits_2d21c0 u;
    u.u = (r & 0x7fffff) | 0x3f800000;
    return u.f - 1.0f;
}

class ParticlePointGenerator {
public:
    char pad00[0x38];
    float f38, f3c, f40;
    float f44, f48, f4c;
    unsigned int vfunc_6(unsigned int count, Mat4_2d21c0* from, Mat4_2d21c0* to, float step, Emitter_2d21c0* em);
};

unsigned int ParticlePointGenerator::vfunc_6(unsigned int count, Mat4_2d21c0* from, Mat4_2d21c0* to, float step, Emitter_2d21c0* em)
{
    if (count == 0)
        return 0;
    float sa = f44 * f38;
    float sb = f48 * f3c;
    float sc = f4c * f40;
    Vec3_2d21c0 p = from->pos;
    float dx = to->pos.x - p.x;
    float dy = to->pos.y - p.y;
    float dz = to->pos.z - p.z;
    volatile float inv = 1.0f / (float)count;
    Vec3_2d21c0 d;
    d.x = dx * inv;
    d.y = dy * inv;
    d.z = dz * inv;
    step = step * inv;
    volatile float t = 0.0f;
    unsigned int n = 0;
    for (unsigned int i = 0; i < count; i++) {
        float v1 = RandomSigned();
        float v2 = RandomSigned();
        float v3 = RandomUnsigned() * sc;
        Vec3_2d21c0 dir;
        FUN_00356bf0(1.0f, v1 * sa + 1.5707964f, v2 * sb + 1.5707964f, &dir.x, &dir.y, &dir.z);
        dir.FUN_0022d260(from);
        dir.FUN_0022d110();
        Vec3_2d21c0 q;
        q.x = dir.x * v3 + p.x;
        q.y = dir.y * v3 + p.y;
        q.z = dir.z * v3 + p.z;
        if (!em->v14(&dir, &q, t))
            break;
        n++;
        p.x += d.x;
        p.y += d.y;
        p.z += d.z;
        t -= step;
    }
    return n;
}
