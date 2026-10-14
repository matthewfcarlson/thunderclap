// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// physics::PhysicsJoint3D::vfunc_12 @ 0x00309d00
extern float DAT_004218f0;

struct V3_309d00 {
    float x, y, z;
};

struct Frame_309d00 {
    char pad0[0x10];
    V3_309d00 v;
    void FUN_002fd730();
};

struct Mid_309d00 {
    char pad0[0x8c];
    Frame_309d00 *frame;
};

struct Basis_309d00 {
    char pad0[0x1c];
    V3_309d00 w;
};

struct Body_309d00 {
    char pad0[0x10];
    Mid_309d00 *mid;
    char pad14[8];
    Basis_309d00 *basis;
    void FUN_00310490(void *a, V3_309d00 *out, int z);
};

namespace physics {

class PhysicsJoint3D {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12(float a1, float a2, float a3, float a4, V3_309d00 *p5, V3_309d00 *p6, float a7);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual float vfunc_20(V3_309d00 *t);
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    char pad4[4];
    void *target;       // 8
    char padc[0xc];
    Body_309d00 *body;         // 0x18
    char pad1c[0xc8];
    float scale;        // 0xe4
    char pade8[0x38];
    V3_309d00 accum;           // 0x120
    char pad12c[0x25];
    char flag151;
};

void PhysicsJoint3D::vfunc_12(float a1, float a2, float a3, float a4, V3_309d00 *p5, V3_309d00 *p6, float a7)
{
    // Values the original keeps in x87 registers are double (80-bit); spills are volatile float.
    V3_309d00 u;
    body->FUN_00310490(target, &u, 0);
    double cx = u.y * p5->z - u.z * p5->y;
    double cy = u.z * p5->x - u.x * p5->z;
    volatile float cz = u.x * p5->y - u.y * p5->x;
    volatile float na1 = -a1;
    V3_309d00 t;
    t.x = (float)(cx * na1);
    double cyn = cy * na1;
    double czn = cz * na1;
    double vx = u.y * p6->z - u.z * p6->y;
    double vy = u.z * p6->x - u.x * p6->z;
    volatile float vz = u.x * p6->y - u.y * p6->x;
    volatile float na2 = -a2;
    t.x = (float)(vx * na2 + t.x);
    t.y = (float)(vy * na2 + cyn);
    t.z = (float)(vz * na2 + czn);
    V3_309d00 *w = &body->basis->w;
    double wx = u.y * w->z - u.z * w->y;
    double wy = u.z * w->x - u.x * w->z;
    volatile float wz = u.x * w->y - u.y * w->x;
    t.x = (float)(wx * a3 + t.x);
    t.y = (float)(wy * a3 + t.y);
    t.z = (float)(wz * a3 + t.z);
    if (a4 != 0.0f) {
        Frame_309d00 *q = body->mid->frame;
        q->FUN_002fd730();
        if (q->v.x * q->v.x + q->v.y * q->v.y + q->v.z * q->v.z > DAT_004218f0) {
            q = body->mid->frame;
            q->FUN_002fd730();
            double r1 = q->v.z * p5->y - q->v.y * p5->z;
            double r2 = p5->z * q->v.x - q->v.z * p5->x;
            double r3 = q->v.y * p5->x - p5->y * q->v.x;
            volatile float x = (float)(u.y * r3 - r2 * u.z);
            volatile float y = (float)(u.z * r1 - r3 * u.x);
            double z = r2 * u.x - u.y * r1;
            t.x = (float)(x * a4 + t.x);
            t.y = (float)(y * a4 + t.y);
            t.z = (float)(z * a4 + t.z);
        }
    }
    double m = a7 * scale;
    t.x = (float)(t.x * m);
    t.y = (float)(t.y * m);
    t.z = (float)(t.z * m);
    float r = vfunc_20(&t);
    if (r > 0.0f) {
        accum.x = t.x * r + accum.x;
        accum.y = t.y * r + accum.y;
        accum.z = t.z * r + accum.z;
        flag151 = 0;
    }
}

}
