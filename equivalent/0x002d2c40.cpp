// STATUS: equivalent (tools/equiv.py level 3: 105 inputs, branch coverage 16/18, incomplete)
// pure3d::ParticleSphereGenerator::vfunc_6 @ 0x002d2c40
struct Vec3 {
    float x, y, z;
    void FUN_0022d260(struct Mat4* m);
    float FUN_0022d110();
};

struct Mat4 {
    float m[12];
    Vec3 pos;
    float w;
};

struct Rng {
    float FUN_00143100();
};

extern Rng DAT_00554bfc;

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
    virtual bool v14(Vec3* dir, Vec3* pos, float t);
};

void __cdecl FUN_00356bf0(float r, float az, float pol, float* x, float* y, float* z);

struct Frame {
    Vec3 tmp;
    Vec3 p;
    Vec3 q1;
    Vec3 w;
    union {
        Vec3 d;
        Vec3 q0;
    };
};

class ParticleSphereGenerator {
public:
    char pad00[0x38];
    float f38, f3c, f40;
    float f44, f48, f4c;
    unsigned int vfunc_6(unsigned int count, Mat4* from, Mat4* to, float step, Emitter* em);
};

unsigned int ParticleSphereGenerator::vfunc_6(unsigned int count, Mat4* from, Mat4* to, float step, Emitter* em)
{
    if (count == 0)
        return 0;
    float radius = f40 * f38;
    float jitter = f44 * f3c;
    Frame fr;
    fr.p = from->pos;
    float dx = fr.p.x - to->pos.x;
    float dy = fr.p.y - to->pos.y;
    float dz = fr.p.z - to->pos.z;
    volatile float inv = 1.0f / (float)count;
    fr.d.x = dx * inv;
    fr.d.y = dy * inv;
    fr.d.z = dz * inv;
    step = step * inv;
    unsigned int n = 0;
    if (radius != 0.0f) {
        volatile float t = 0.0f;
        for (unsigned int i = 0; i < count; i++) {
            float ph = DAT_00554bfc.FUN_00143100() * 3.1415927f;
            float th = DAT_00554bfc.FUN_00143100() * 3.1415927f;
            float v = DAT_00554bfc.FUN_00143100() * jitter;
            Vec3& w = fr.w;
            FUN_00356bf0(radius, ph, th, &fr.tmp.x, &fr.tmp.y, &fr.tmp.z);
            w = fr.tmp;
            w.FUN_0022d260(from);
            Vec3& q = fr.q1;
            q = w;
            w.FUN_0022d110();
            q.x = w.x * v + (q.x + fr.p.x);
            q.y = w.y * v + (q.y + fr.p.y);
            q.z = w.z * v + (q.z + fr.p.z);
            if (!em->v14(&w, &q, t))
                break;
            n++;
            fr.p.x += fr.d.x;
            fr.p.y += fr.d.y;
            fr.p.z += fr.d.z;
            t += step;
        }
    } else {
        for (unsigned int i = 0; i < count; i++) {
            float ph = DAT_00554bfc.FUN_00143100() * 3.1415927f;
            float th = DAT_00554bfc.FUN_00143100() * 3.1415927f;
            float v = DAT_00554bfc.FUN_00143100() * jitter;
            Vec3& w = fr.w;
            FUN_00356bf0(1.0f, ph, th, &w.x, &w.y, &w.z);
            w.FUN_0022d260(from);
            w.FUN_0022d110();
            Vec3& q = fr.q0;
            q.x = w.x * v + from->pos.x;
            q.y = w.y * v + from->pos.y;
            q.z = w.z * v + from->pos.z;
            if (!em->v14(&w, &q, 0.0f))
                break;
            n++;
        }
    }
    return n;
}
