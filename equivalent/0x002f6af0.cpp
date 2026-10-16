// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 35/36, incomplete)
// physics::PhysicsObject::vfunc_38 @ 0x002f6af0
#include "decls/data/engine/physics.h"

extern "C" double sqrt(double);
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct Vec3_2f6af0 {
    float x, y, z;
    void FUN_0022d260(struct Mat_2f6af0 *m) throw();
};

struct Quat_2f6af0 {
    float q[4];
    void FUN_0022b120() throw();
    void FUN_0022b650(struct Mat_2f6af0 *m) throw();
};

struct Mat_2f6af0 {
    float m[16];
    void FUN_0022c3b0(Vec3_2f6af0 *in, Vec3_2f6af0 *out) throw();
    void FUN_0022be40(Vec3_2f6af0 *p) throw();
};

struct Integ {
    void FUN_002fd020(Vec3_2f6af0 *a, Vec3_2f6af0 *b) throw();
};

class Body_2f6af0 {
public:
    virtual void v0() throw();
    virtual void v1() throw();
    virtual void v2() throw();
    virtual void v3() throw();
    virtual void v4() throw();
    virtual void v5() throw();
    virtual void v6(Mat_2f6af0 *m, float dt) throw();
    virtual void v7() throw();
    virtual void v8(Vec3_2f6af0 *p, Vec3_2f6af0 *q, int z) throw();
    char pad04[0x58];
    Vec3_2f6af0 a;
    union {
        float f68;
        unsigned int u68;
    };
};

char __cdecl FUN_003059c0(Vec3_2f6af0 *a, Quat_2f6af0 *z) throw();
void *__cdecl FUN_0022b080(void *a, void *b, void *c) throw();
void __cdecl FUN_00305700(unsigned int s, Mat_2f6af0 *src, Mat_2f6af0 *dst) throw();

class PhysicsObject {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
    virtual void vfunc_2() throw();
    virtual void vfunc_3() throw();
    virtual void vfunc_4() throw();
    virtual void vfunc_5() throw();
    virtual void vfunc_6() throw();
    virtual void vfunc_7() throw();
    virtual void vfunc_8() throw();
    virtual void vfunc_9() throw();
    virtual void vfunc_10() throw();
    virtual void vfunc_11() throw();
    virtual void vfunc_12() throw();
    virtual void vfunc_13() throw();
    virtual void vfunc_14() throw();
    virtual void vfunc_15() throw();
    virtual void vfunc_16() throw();
    virtual void vfunc_17() throw();
    virtual void vfunc_18() throw();
    virtual void vfunc_19() throw();
    virtual void vfunc_20() throw();
    virtual void vfunc_21() throw();
    virtual void vfunc_22() throw();
    virtual void vfunc_23() throw();
    virtual void vfunc_24() throw();
    virtual void vfunc_25() throw();
    virtual void vfunc_26() throw();
    virtual void vfunc_27() throw();
    virtual void vfunc_28() throw();
    virtual void vfunc_29() throw();
    virtual void vfunc_30() throw();
    virtual void vfunc_31() throw();
    virtual void vfunc_32() throw();
    virtual void vfunc_33() throw();
    virtual void vfunc_34() throw();
    virtual void vfunc_35() throw();
    virtual void vfunc_36() throw();
    virtual void vfunc_37() throw();
    virtual void vfunc_38(float dt);
    virtual void vfunc_39() throw();
    char pad04[0xc];
    Body_2f6af0 *f10;
    char pad14[0x10];
    int f24;
    char pad28[0x1c];
    float f44;
    int f48;
    Vec3_2f6af0 v4c;
    Mat_2f6af0 mat58;
    Vec3_2f6af0 v98;
    char ba4;
    char pada5[3];
    Vec3_2f6af0 va8;
    Vec3_2f6af0 vb4;
    Vec3_2f6af0 vc0;
    Quat_2f6af0 vcc;
    char padDC[0xf8 - 0xdc];
    Integ m_f8;
    char padF9[0x114 - 0xf9];
    Integ m_114;
    char pad115[0x130 - 0x115];
    Vec3_2f6af0 v130;
    Vec3_2f6af0 v13c;
    char pad148[0x164 - 0x148];
    float f164;
    char pad168[0x1cc - 0x168];
    float f1cc;
    char b1d0;
    void FUN_002f5a20(Vec3_2f6af0 *q) throw();
};

void PhysicsObject::vfunc_38(float dt)
{
    struct Frame {
        float s0;
        Vec3_2f6af0 A;
        Vec3_2f6af0 Y;
        Vec3_2f6af0 Q;
        Quat_2f6af0 Z;
        Mat_2f6af0 M2;
    } f;

    double kk = 1.0f - dt * f164;
    f.s0 = (float)kk;
    bool run = true;
    if (kk < 1.0f) {
        if (!(f.s0 > 0.0f))
            run = false;
    } else {
        f.s0 = 1.0f;
    }
    if (run) {
        if (!(f1cc < DAT_00555458) || f24 != 0 || f48 >= 4) {
            vc0.x = f.s0 * vc0.x;
            vc0.y = f.s0 * vc0.y;
            vc0.z = f.s0 * vc0.z;
        } else {
            int m = f48;
            if (m >= 0) {
                if (m > 2) {
                    mat58.FUN_0022c3b0(&v4c, &f.Y);
                } else {
                    f.Y = *(Vec3_2f6af0 *)((char *)this + 0x58 + (m << 4));
                }
            }
            Body_2f6af0 *o = f10;
            double dotAY = o->a.z * f.Y.z + o->a.y * f.Y.y + o->a.x * f.Y.x;
            double s = -((1.0f - f.s0) * dotAY);
            double ypx = f.Y.x * s;
            f.Z.q[1] = f.Y.y * s;
            f.Z.q[2] = f.Y.z * s;
            o->a.x = ypx + o->a.x;
            o->a.y = f.Z.q[1] + o->a.y;
            o->a.z = f.Z.q[2] + o->a.z;
            m_f8.FUN_002fd020(&f10->a, &vc0);
        }
    }
    f10->v8(&v98, &f.Q, -1);
    double qxo = f.Q.x;
    double qyo = f.Q.y;
    float qzo = f.Q.z;
    f.A.z = qzo;
    double h = dt * f44;
    f.Q.x = h * v130.x + f.Q.x;
    f.Q.y = h * v130.y + f.Q.y;
    f.Q.z = h * v130.z + f.Q.z;
    Vec3_2f6af0 *a = &f10->a;
    f.A.x = a->x;
    f.A.y = a->y;
    f.A.z = a->z;
    char b = b1d0;
    f.Y.x = (float)(qxo + f.Q.x);
    double ys = qyo + f.Q.y;
    double zs = f.Q.z + qzo;
    f.s0 = (float)(dt * 0.5f);
    f.Y.x = f.Y.x * f.s0;
    f.Y.y = ys * f.s0;
    f.Y.z = zs * f.s0;
    if (b != 0) {
        vc0.x = dt * v13c.x + vc0.x;
        vc0.y = dt * v13c.y + vc0.y;
        vc0.z = dt * v13c.z + vc0.z;
    }
    m_114.FUN_002fd020(&vc0, &f10->a);
    Body_2f6af0 *ec = f10;
    double sum2 = ec->a.x * ec->a.x + ec->a.y * ec->a.y + ec->a.z * ec->a.z;
    bool skipNext = false;
    if (sum2 > DAT_004d2ba0) {
        double sc = DAT_004d2b84 / sqrt(sum2);
        ec->a.x = sc * ec->a.x;
        ec->a.y = sc * ec->a.y;
        ec->a.z = sc * ec->a.z;
        m_f8.FUN_002fd020(&f10->a, &vc0);
    } else if (sum2 < DAT_004d2ba4) {
        if (sum2 > 0.0f) {
            ec->a.z = 0.0f;
            ec->a.y = 0.0f;
            ec->a.x = 0.0f;
            vc0.z = 0.0f;
            vc0.y = 0.0f;
            vc0.x = 0.0f;
        }
        if (f.A.z * f.A.z + f.A.y * f.A.y + f.A.x * f.A.x < DAT_004d2ba4) {
            f.A.z = 0.0f;
            f.A.y = 0.0f;
            f.A.x = 0.0f;
            skipNext = true;
        }
    }
    if (!skipNext) {
        Vec3_2f6af0 *pa = &f10->a;
        f.A.x = f.A.x + pa->x;
        f.A.y = f.A.y + pa->y;
        double azs = f.A.z + pa->z;
        f.A.x = f.A.x * f.s0;
        f.A.y = f.A.y * f.s0;
        f.A.z = azs * f.s0;
        if (FUN_003059c0(&f.A, &f.Z)) {
            Quat_2f6af0 *edi = &vcc;
            FUN_0022b080(&f.Z, &f.Z, edi);
            vcc.q[0] = f.Z.q[0];
            vcc.q[1] = f.Z.q[1];
            vcc.q[2] = f.Z.q[2];
            vcc.q[3] = f.Z.q[3];
            vcc.FUN_0022b120();
            vcc.FUN_0022b650(&mat58);
        }
        vfunc_39();
    }
    if (b1d0 == 0)
        m_114.FUN_002fd020(&vc0, &f10->a);
    else
        m_f8.FUN_002fd020(&f10->a, &vc0);
    v98.x = f.Y.x + v98.x;
    v98.y = f.Y.y + v98.y;
    v98.z = f.Y.z + v98.z;
    if (f10->u68 != 0x3f800000)
        FUN_00305700(f10->u68, &mat58, &f.M2);
    else
        memcpy(&f.M2, &mat58, 64);
    if (ba4 == 0) {
        f.Y.x = va8.x + vb4.x;
        f.Y.y = va8.y + vb4.y;
        f.Y.z = va8.z + vb4.z;
        f.Y.FUN_0022d260(&mat58);
        double sc = f10->f68;
        double txs = f.Y.x * sc;
        f.Y.y = f.Y.y * sc;
        f.Y.z = f.Y.z * sc;
        f.Y.x = v98.x - txs;
        f.Y.y = v98.y - f.Y.y;
        f.Y.z = v98.z - f.Y.z;
        f.M2.FUN_0022be40(&f.Y);
    } else {
        f.M2.FUN_0022be40(&v98);
    }
    f10->v6(&f.M2, dt);
    FUN_002f5a20(&f.Q);
}
