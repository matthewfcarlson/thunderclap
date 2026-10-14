// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 25/26, incomplete)
// FUN_00315ca0 @ 0x00315ca0
// equiv-map: ?thunk_FUN_002fb860@Body@@QAEXPAUVec3@@H@Z = 0x002fb940
extern "C" double __cdecl sqrt(double);

struct Vec3_315ca0 {
    float x, y, z;
    float FUN_0022d110();
};

union FloatBits_315ca0 {
    float f;
    unsigned int u;
};

class Body {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual Vec3_315ca0 *vfunc_4();
    char pad04[0x44 - 4];
    Vec3_315ca0 n;                          // 0x44
    float f50;                       // 0x50
    float f54;                       // 0x54
    char b58;                        // 0x58
    void thunk_FUN_002fb860(Vec3_315ca0 *out, int i);
};

float __cdecl FUN_00083d90(float *v);

// The original keeps this reciprocal unrounded on the FPU stack (double here, to avoid the compiler folding it).
static double Reciprocal(float r, float f54)
{
    return -1.0f / (r + f54);
}

class Resolver_315ca0 {
public:
    char pad00[0x0c];
    float threshold;                 // 0x0c
    char pad10[4];
    Vec3_315ca0 offset;                     // 0x14
    Vec3_315ca0 dir;                        // 0x20
    void FUN_00314be0(Body *a, Vec3_315ca0 *pa, Body *b, Vec3_315ca0 *pb, float depth, Vec3_315ca0 *dir);
    void FUN_00315ca0(Body *a1, Body *a2);
};

void Resolver_315ca0::FUN_00315ca0(Body *a1, Body *a2)
{
    float skip;
    if (a2->b58)
        skip = 0.0f;
    else
        skip = a2->f54;

    for (int i = 0; i < 4; i++) {
        Vec3_315ca0 v;
        Vec3_315ca0 c;
        Vec3_315ca0 w;
        struct {
            float t;
            float r;
        } tr;
        FloatBits_315ca0 ad;
        FloatBits_315ca0 at;
        a1->thunk_FUN_002fb860(&v, i);

        float dot = v.z * offset.z + v.y * offset.y + v.x * offset.x;
        ad.f = dot;
        ad.u &= 0x7fffffff;
        if (!(ad.f > 1e-6f))
            continue;
        if (dot > 0.0f) {
            v.x = v.x * -1.0f;
            v.y = v.y * -1.0f;
            v.z = v.z * -1.0f;
        }
        w.x = v.x + offset.x;
        w.y = v.y + offset.y;
        w.z = v.z + offset.z;
        tr.t = w.z * a2->n.z + w.y * a2->n.y + w.x * a2->n.x;
        at.f = tr.t;
        at.u &= 0x7fffffff;
        float dist = at.f - a2->f50;
        if (!(dist - skip <= threshold))
            continue;

        float nt = -tr.t;
        dir.x = nt * a2->n.x;
        dir.y = nt * a2->n.y;
        dir.z = nt * a2->n.z;
        dir.x = w.x + dir.x;
        dir.y = w.y + dir.y;
        dir.z = w.z + dir.z;
        // (the original reloads the stored float components here rather than reusing the unrounded sums)
        volatile float *dv = &dir.x;
        tr.r = (float)sqrt(dv[0] * dv[0] + dv[1] * dv[1] + dv[2] * dv[2]) - a2->f54;
        if (!(tr.r <= threshold))
            continue;

        if (a2->b58 == 0 && at.f >= a2->f50) {
            float s2 = -(FUN_00083d90(&tr.t) * a2->f50);
            dir.x = s2 * a2->n.x;
            dir.y = s2 * a2->n.y;
            dir.z = s2 * a2->n.z;
            dir.x = w.x + dir.x;
            dir.y = w.y + dir.y;
            dir.z = w.z + dir.z;
            tr.r = dir.FUN_0022d110() - a2->f54;
            if (!(tr.r <= threshold))
                continue;
            Vec3_315ca0 *p = a1->vfunc_4();
            v.x = v.x + p->x;
            v.y = v.y + p->y;
            v.z = v.z + p->z;
            float nr = -tr.r;
            float yp = nr * dir.y;
            float zp = nr * dir.z;
            c.x = nr * dir.x + v.x;
            c.y = yp + v.y;
            c.z = zp + v.z;
        } else {
            Vec3_315ca0 *p = a1->vfunc_4();
            v.x = v.x + p->x;
            v.y = v.y + p->y;
            v.z = v.z + p->z;
            if (a2->b58 != 0 && -threshold < dist) {
                float sg = FUN_00083d90(&tr.t);
                tr.r = dist;
                dir.x = sg * a2->n.x;
                dir.y = sg * a2->n.y;
                dir.z = sg * a2->n.z;
                float nd = -dist;
                c.x = nd * dir.x + v.x;
                c.y = nd * dir.y + v.y;
                c.z = nd * dir.z + v.z;
            } else {
                if (tr.r == -a2->f54)
                    continue;
                double inv = Reciprocal(tr.r, a2->f54);
                dir.x = inv * dir.x;
                dir.y = inv * dir.y;
                dir.z = inv * dir.z;
                float zp = tr.r * dv[2];
                c.x = tr.r * dv[0] + v.x;
                c.y = tr.r * dv[1] + v.y;
                c.z = zp + v.z;
                if (dist > 0.0f) {
                    float sd = -(FUN_00083d90(&tr.t) * dist);
                    c.x = sd * a2->n.x + c.x;
                    c.y = sd * a2->n.y + c.y;
                    c.z = sd * a2->n.z + c.z;
                    dir.x = v.x - c.x;
                    dir.y = v.y - c.y;
                    dir.z = v.z - c.z;
                    tr.r = dir.FUN_0022d110();
                } else {
                    dir.x = dir.x * -1.0f;
                    dir.y = dir.y * -1.0f;
                    dir.z = dir.z * -1.0f;
                }
            }
        }
        FUN_00314be0(a1, &v, a2, &c, tr.r, &dir);
    }
}
