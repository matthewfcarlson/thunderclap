// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 8/8)
// physics::SimpleFilter1D::vfunc_1 @ 0x003195d0
#include "compat/ptr.h"
namespace physics {

class Filter1D {
public:
    virtual void vfunc_0();
    virtual hulk_freg vfunc_1(float x, float target);
    virtual void vfunc_2();
    float rate;         // 4
    float alpha;        // 8
    float state;        // 0xc
    float lastTarget;   // 0x10
};

class SimpleFilter1D : public Filter1D {
public:
    virtual void vfunc_0();
    virtual hulk_freg vfunc_1(float x, float target);
    virtual void vfunc_2();
};

hulk_freg SimpleFilter1D::vfunc_1(float x, float target)
{
    if (lastTarget != target) {
        alpha = target * rate;
        if (alpha <= 0.0f)
            alpha = 0.0f;
        else if (alpha > 0.999999f)
            alpha = 0.999999f;
        if (lastTarget == 0.0f)
            state = (state * 1.5f - x * alpha) / (1.0f - alpha);
        lastTarget = target;
    }
    hulk_freg result = (x - state) * alpha + state;
    state = result;
    return result; // the original returns the unrounded register
}

}
