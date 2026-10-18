// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// choreo2::AnimationDriver::vfunc_13 @ 0x002258f0
namespace choreo2 {
class AnimationDriver {
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
    virtual bool vfunc_13();
    char pad4[0x224 - 4];
    bool finished;
    bool paused;
    float rate;
    float upper;
    float lower;
    char pad234[8];
    float time;
};

bool AnimationDriver::vfunc_13()
{
    if (finished)
        return false;
    if (!paused) {
        if (rate >= 0.0f)
            return time >= lower;
        return time <= upper;
    }
    return false;
}
}
