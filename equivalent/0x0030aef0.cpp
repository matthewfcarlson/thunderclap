// STATUS: equivalent (tools/equiv.py level 3: 80 inputs, branch coverage 35/36, incomplete)
// physics::PhysicsJoint1D::vfunc_11 @ 0x0030aef0
extern float DAT_003f32dc;  // 1.0
extern float DAT_003f32e0;  // 0.0
extern float DAT_00417e28;  // -pi
extern float DAT_00431dbc;  // pi
extern float DAT_004d318c;  // 5.0
extern float DAT_004d3190;  // 0.0001
extern float DAT_004d31a0;  // 0.01
extern float DAT_004d31a4;  // 0.625
extern float DAT_004d31a8;  // 0.625
extern float DAT_004d31b4;  // 1.0

float __cdecl FUN_00083d90(float *value);

static inline float Abs(float v)
{
    union {
        float f;
        unsigned int u;
    } b;
    b.f = v;
    b.u &= 0x7fffffff;
    return b.f;
}

class PhysicsJoint1D {
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
    char pad04[0x10 - 4];
    float limit10;
    float limit14;
    char pad18[0xf4 - 0x18];
    int mode;
    char flag;
    char padf9[0x10c - 0xf9];
    float pos;      // 0x10c
    float posGoal;  // 0x110
    float vel;      // 0x114
    float velGoal;  // 0x118
};

void PhysicsJoint1D::vfunc_11(float a1, float a2, float a3)
{
    if (pos == DAT_003f32e0 && vel == DAT_003f32e0)
        return;

    float newVel = (velGoal - vel) * DAT_004d31a4 * a3 + vel;
    float newPos = ((posGoal - pos) * DAT_004d31a8 * a3 + pos) * a2;
    vel = newVel;
    pos = newPos;

    switch (mode) {
    case 0: {
        float v = FUN_00083d90(&vel) * (DAT_003f32dc - a1) * DAT_004d31b4;
        if (Abs(v) < Abs(newVel))
            vel = newVel - v;
        else
            vel = 0.0f;
        break;
    }
    case 1:
        if ((DAT_003f32dc - a1) * Abs(newVel) < DAT_004d31b4)
            vel = newVel * a1;
        else
            vel = (DAT_003f32dc - DAT_004d31b4 / Abs(newVel)) * newVel;
        break;
    }

    volatile float xs = newPos * a3 + vel;
    float x = xs;
    vel = x;
    if (x > DAT_00431dbc) {
        float v = vel;
        do {
            v -= DAT_00431dbc;
        } while (v > DAT_00431dbc);
        vel = v;
    } else if (x < DAT_00431dbc && x < DAT_00417e28) {
        float v = vel;
        do {
            v += DAT_00431dbc;
        } while (v < DAT_00417e28);
        vel = v;
    }

    if (Abs(vel) > DAT_004d3190) {
        if (Abs(vel) > DAT_004d318c)
            vel = FUN_00083d90(&vel) * DAT_004d318c;
        bool damp = false;
        if (flag) {
            if (limit14 - limit10 < vel)
                damp = true;
            else if (-(limit14 - limit10) > vel)
                damp = true;
        }
        if (!damp) {
            if (vel > limit14)
                damp = true;
            else if (-limit10 > vel)
                damp = true;
        }
        if (damp)
            vel = (DAT_003f32dc - DAT_004d31a0) * vel;
    } else {
        vfunc_2();
    }
    velGoal = vel;
    posGoal = pos;
}
