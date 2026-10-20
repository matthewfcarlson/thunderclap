// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 28/28)
// physics::PhysicsJoint3D::vfunc_20 @ 0x0030bac0
#include "decls/data/engine/physics.h"

struct Vec3_30bac0 {
    float x, y, z;
};

struct World {
    char pad00[0x224];
    float dt;
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
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual float vfunc_20(Vec3_30bac0 *dir);
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    float FUN_0030adc0(float a, float b, float lo, float hi);

    char pad04[0x10 - 4];
    float lo;
    float hi;
    World *world;
    char pad1c[0x98 - 0x1c];
    Vec3_30bac0 a;
    char pada4[0xfc - 0xa4];
    Vec3_30bac0 b;
    volatile Vec3_30bac0 c;
    char pad114[0x120 - 0x114];
    Vec3_30bac0 d;
    char pad12c[0x154 - 0x12c];
    float f154;
    float f158;
};

float PhysicsJoint3D::vfunc_20(Vec3_30bac0 *dir)
{
    float cap = DAT_004d3198;
    float r1 = 1.0f;
    float r2 = 1.0f;
    float e1 = a.x * d.x + (a.y * d.y + a.z * d.z);
    float e2 = a.x * dir->x + (a.y * dir->y + a.z * dir->z);
    if (e2 != 0.0f) {
        World *w = world;
        r1 = FUN_0030adc0(e1 * w->dt + f158, e2 * w->dt, -DAT_004d3194, DAT_004d3194);
        if (!(r1 > 0.0f)) {
            return 0.0f;
        }
        r2 = FUN_0030adc0(e1, e2, -DAT_004d3198, cap);
        if (r2 == 0.0f) {
            return 0.0f;
        }
    }

    float r3 = 1.0f;
    float r4 = 1.0f;
    float e3 = b.x * d.x + (b.y * d.y + b.z * d.z);
    float e4 = b.x * dir->x + (b.y * dir->y + b.z * dir->z);
    if (e4 != 0.0f) {
        World *w = world;
        r3 = FUN_0030adc0(e3 * w->dt + f154, e4 * w->dt, lo, hi);
        if (r3 == 0.0f) {
            return 0.0f;
        }
        r4 = FUN_0030adc0(e3, e4, -DAT_004d3198, cap);
        if (r4 == 0.0f) {
            return 0.0f;
        }
    }

    c.x = b.y * a.z - b.z * a.y;
    c.y = a.x * b.z - a.z * b.x;
    c.z = a.y * b.x - a.x * b.y;
    float e5 = c.x * d.x + (c.y * d.y + c.z * d.z);
    float e6 = c.x * dir->x + (c.y * dir->y + c.z * dir->z);
    float m = 1.0f;
    if (e6 != 0.0f) {
        World *w = world;
        float r5 = FUN_0030adc0(e5 * w->dt, e6 * w->dt, lo, hi);
        if (r5 == 0.0f) {
            return 0.0f;
        }
        float r6 = FUN_0030adc0(e5, e6, -DAT_004d3198, cap);
        if (r6 == 0.0f) {
            return 0.0f;
        }
        m = (r5 < r6) ? r5 : r6;
    }
    m = (m < r3) ? m : r3;
    m = (m < r4) ? m : r4;
    m = (m < r1) ? m : r1;
    m = (m < r2) ? m : r2;
    return m;
}

}
