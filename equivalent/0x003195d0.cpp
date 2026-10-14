// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// physics::SimpleFilter1D::vfunc_1 @ 0x003195d0
namespace physics {

class Filter1D {
public:
    virtual void vfunc_0();
    virtual float vfunc_1(float x, float target);
    virtual void vfunc_2();
    float rate;         // 4
    float alpha;        // 8
    float state;        // 0xc
    float lastTarget;   // 0x10
};

class SimpleFilter1D : public Filter1D {
public:
    virtual void vfunc_0();
    virtual float vfunc_1(float x, float target);
    virtual void vfunc_2();
};

float SimpleFilter1D::vfunc_1(float x, float target)
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
    state = (x - state) * alpha + state;
    return state;
}

}
