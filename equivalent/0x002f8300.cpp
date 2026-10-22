// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 12/12)
// FUN_002f8300 @ 0x002f8300
#include "compat/ptr.h"
extern "C" double sqrt(double);
struct V3_2f8300 {
    float x, y, z;
};

struct Peer_2f8300 {
    char pad[0x1c];
    float f1c;
};

struct SymMatrix {
    char pad[4];
    float f4;
    char rest[0x14];
    void FUN_002fcb30(void *a, void *b) throw();
    void FUN_002fca90() throw();
    void FUN_002fcaa0() throw();
    void FUN_002fd0c0(SymMatrix *src) throw();
    void FUN_002fd020(V3_2f8300 *in, V3_2f8300 *out) throw();
};

struct Target_2f8300 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7(V3_2f8300 *r, void *p);
};

float FUN_002f2950(float a, float b);

struct ImpulseBasedCollisionSolver_2f8300 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual float v4();
    Target_2f8300 *target;                 // 0x04
    char pad08[4];
    char pos[8];                    // 0x0c
    Peer_2f8300 *peer14;                   // 0x14
    Peer_2f8300 *peer18;                   // 0x18
    char pad1c[8];
    V3_2f8300 dir;                         // 0x24
    char pad30[0x20];
    V3_2f8300 res;                         // 0x50
    char pad5c[0x18];
    V3_2f8300 vec74;                       // 0x74
    float f80;                      // 0x80
    char pad84[0x10];
    char a94[0x1c];                 // 0x94
    char ab0[0x1c];                 // 0xb0
    SymMatrix mat;                  // 0xcc
    char padE8[0xb];
    char fF3;
    char fF4;
    float FUN_002f7ca0() throw();
    int FUN_002f8300();
};

int ImpulseBasedCollisionSolver_2f8300::FUN_002f8300()
{
    volatile V3_2f8300 *r = &res;
    struct Frame {
        float f10;
        float f14;
        float f18;
        float f1c;
        float f20;
        V3_2f8300 d;
        V3_2f8300 a30;
        V3_2f8300 v3c;
        V3_2f8300 v48;
        SymMatrix m54;
    } fr;

    r->z = 0.0f;
    r->y = 0.0f;
    r->x = 0.0f;
    mat.FUN_002fcb30(a94, ab0);
    if (mat.f4 == 0.0f)
        return 1;
    fr.f1c = v4() - 1.0f;
    if (fF3 == 0)
        fr.f10 = FUN_002f2950(peer14->f1c, peer18->f1c);
    else
        *(int *)&fr.f10 = 0;
    fr.f20 = FUN_002f7ca0();
    fr.d = dir;
    fr.m54.FUN_002fca90();
    fr.m54.FUN_002fd0c0(&mat);
    mat.FUN_002fd020(&fr.d, &fr.v3c);
    hulk_freg s = (-1.0f / (fr.v3c.z * fr.d.z + fr.v3c.y * fr.d.y + fr.v3c.x * fr.d.x)) * f80;
    fr.a30.x = fr.d.x * s;
    fr.a30.y = fr.d.y * s;
    fr.a30.z = fr.d.z * s;
    if (fF4 != 0) {
        if (fr.f10 == 0.0f) {
            r->x = fr.a30.x;
            r->y = fr.a30.y;
            r->z = fr.a30.z;
        } else {
            fr.m54.FUN_002fd020(&vec74, &fr.v48);
            r->x = fr.v48.x + fr.a30.x;
            r->y = fr.v48.y + fr.a30.y;
            r->z = fr.v48.z + fr.a30.z;
            r->x = r->x * -1.0f;
            r->y = r->y * -1.0f;
            r->z = r->z * -1.0f;
            double w = fr.f1c + 1.0f;
            r->x = fr.a30.x * w + r->x;
            r->y = fr.a30.y * w + r->y;
            r->z = fr.a30.z * w + r->z;
        }
    } else {
        fr.m54.FUN_002fd020(&vec74, &fr.v48);
        double x0 = fr.v48.x + fr.a30.x;
        r->x = (float)x0;
        fr.f14 = fr.v48.y + fr.a30.y;
        r->y = fr.f14;
        fr.f18 = fr.v48.z + fr.a30.z;
        r->z = fr.f18;
        double u = fr.f20 + 1.0f;
        double nu = -u;
        r->x = nu * r->x;
        r->y = nu * r->y;
        r->z = nu * r->z;
        double w = fr.f1c + 1.0f;
        fr.f1c = (float)w;
        r->x = fr.a30.x * w + r->x;
        r->y = fr.a30.y * w + r->y;
        r->z = fr.a30.z * w + r->z;
        double q = fr.d.z * r->z + fr.d.y * r->y + fr.d.x * r->x;
        double nq = -q;
        fr.v3c.x = fr.d.x * nq + r->x;
        fr.v3c.y = fr.d.y * nq + r->y;
        fr.v3c.z = fr.d.z * nq + r->z;
        double P = (fr.d.z * r->z + fr.d.y * r->y + fr.d.x * r->x) * fr.f10;
        double L = fr.v3c.z * fr.v3c.z + fr.v3c.y * fr.v3c.y + fr.v3c.x * fr.v3c.x;
        double R;
        if (P * P < L) {
            fr.v3c.z = fr.f18;
            fr.v3c.y = fr.f14;
            double dd = fr.v48.z * fr.d.z + fr.v48.y * fr.d.y + fr.v48.x * fr.d.x;
            double x = fr.d.x * dd + fr.v48.x;
            double y = fr.d.y * dd + fr.v48.y;
            double z = fr.d.z * dd + fr.v48.z;
            double S = z * z + y * y + x * x;
            fr.v3c.x = (float)x0;
            double sq = sqrt(S);
            double T = sq + (fr.v3c.z * fr.d.z + fr.v3c.y * fr.d.y + fr.v3c.x * fr.d.x) * fr.f10;
            if (T == 0.0) {
                r->z = 0.0f;
                r->y = 0.0f;
                r->x = 0.0f;
                fr.m54.FUN_002fcaa0();
                return 1;
            }
            double DD = fr.a30.z * fr.d.z + fr.a30.y * fr.d.y + fr.a30.x * fr.d.x;
            R = DD / T * fr.f1c * fr.f10;
        } else {
            R = u;
        }
        r->x = (float)x0;
        r->y = fr.f14;
        r->z = fr.f18;
        double nr = -R;
        r->x = nr * r->x;
        r->y = nr * r->y;
        r->z = nr * r->z;
        double w2 = fr.f1c;
        r->x = fr.a30.x * w2 + r->x;
        r->y = fr.a30.y * w2 + r->y;
        r->z = fr.a30.z * w2 + r->z;
    }
    int ret = target->v7((V3_2f8300 *)r, pos);
    fr.m54.FUN_002fcaa0();
    return ret;
}
