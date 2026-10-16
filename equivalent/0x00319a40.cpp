// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// physics::DoubleKalmann1D::vfunc_1 @ 0x00319a40
#include "decls/data/game/global.h"

class Filter_319a40 {
public:
    virtual float v0(float a, int b);
    virtual float v1(float a, int b);
};
class DoubleKalmann1D {
public:
    virtual void vfunc_0();
    virtual float vfunc_1(float x, float dt);
    virtual void vfunc_2();
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    Filter_319a40 filter;
    char pad20[0x38 - 0x20];
    float f38;
};

float DoubleKalmann1D::vfunc_1(float x, float dt)
{
    float vel = (x - f38) / dt;
    f4 = vel;
    Filter_319a40 *flt = &filter;
    f4 = flt->v1(vel, 0);
    f38 = x;
    float k = fc / (f10 + fc);
    f8 = k;
    fc = (((*(float*)&DAT_003f32dc) - k) * fc) + f14;
    f18 = (((x - f18) * *(volatile float *)&f8) + (dt * *(volatile float *)&f4)) + f18;
    return f18;
}
