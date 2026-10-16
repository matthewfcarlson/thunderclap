// STATUS: equivalent (tools/equiv.py level 3: 3010 inputs, branch coverage 18/18)
// physics::PhysicsJoint3D::vfunc_11 @ 0x0030b4c0
#include "decls/data/engine/physics.h"

extern "C" double sqrt(double);

struct Vec3_30b4c0 {
    float x, y, z;
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
    virtual void vfunc_11(float a1, float a2, float a3);
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();

    char pad04[0x10 - 4];
    float f10;
    float f14;
    char pad18[0xf4 - 0x18];
    int mode;
    char padf8[0x120 - 0xf8];
    volatile Vec3_30b4c0 pos;
    Vec3_30b4c0 posTarget;
    volatile Vec3_30b4c0 vel;
    Vec3_30b4c0 velTarget;
    char settled;
    char flag151;
};

void PhysicsJoint3D::vfunc_11(float a1, float a2, float a3)
{
    if (flag151 == 1 && settled == 1) {
        return;
    }
    float dx = posTarget.x - pos.x;
    float dy = posTarget.y - pos.y;
    float dz = posTarget.z - pos.z;
    float step = DAT_004d31a8 * a3;
    pos.x = dx * step + pos.x;
    pos.y = dy * step + pos.y;
    pos.z = dz * step + pos.z;

    float ex = velTarget.x - vel.x;
    float ey = velTarget.y - vel.y;
    float ez = velTarget.z - vel.z;
    float step2 = DAT_004d31a4 * a3;
    vel.x = ex * step2 + vel.x;
    vel.y = ey * step2 + vel.y;
    vel.z = ez * step2 + vel.z;

    pos.x = a2 * pos.x;
    pos.y = a2 * pos.y;
    pos.z = a2 * pos.z;

    if (mode == 0) {
        double v = (1.0f - a1) * DAT_004d31b4;
        double s = vel.x * vel.x + (vel.y * vel.y + vel.z * vel.z);
        if (!(v * v >= s)) {
            double m = v * (-1.0f / sqrt(s));
            vel.x = m * vel.x + vel.x;
            vel.y = m * vel.y + vel.y;
            vel.z = m * vel.z + vel.z;
        } else {
            vel.z = 0.0f;
            vel.y = 0.0f;
            vel.x = 0.0f;
        }
    } else if (mode == 1) {
        double s = vel.x * vel.x + (vel.y * vel.y + vel.z * vel.z);
        double w = 1.0f - a1;
        if (DAT_004d31b8 > w * w * s) {
            vel.x = a1 * vel.x;
            vel.y = a1 * vel.y;
            vel.z = a1 * vel.z;
        } else {
            double u = 1.0f - sqrt(DAT_004d31b8 / s);
            vel.x = u * vel.x;
            vel.y = u * vel.y;
            vel.z = u * vel.z;
        }
    }

    vel.x = a3 * pos.x + vel.x;
    vel.y = a3 * pos.y + vel.y;
    vel.z = a3 * pos.z + vel.z;

    double s2 = vel.x * vel.x + (vel.y * vel.y + vel.z * vel.z);
    if (s2 > (double)DAT_004d3190 * DAT_004d3190) {
        double f;
        bool scale = true;
        if (s2 > (double)DAT_004d318c * DAT_004d318c) {
            f = DAT_004d318c / sqrt(s2);
        } else {
            double d = f14 - f10;
            if (s2 > d * d) {
                f = 1.0f - DAT_004d31a0;
            } else {
                scale = false;
            }
        }
        if (scale) {
            vel.x = f * vel.x;
            vel.y = f * vel.y;
            vel.z = f * vel.z;
        }
        settled = 0;
    } else {
        vfunc_2();
    }

    velTarget.x = vel.x;
    velTarget.y = vel.y;
    velTarget.z = vel.z;
    posTarget.x = pos.x;
    posTarget.y = pos.y;
    posTarget.z = pos.z;
}

}
