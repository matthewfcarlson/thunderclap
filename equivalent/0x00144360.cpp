// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 14/14)
// hulkfight::motion::MotionBlurAction::vfunc_5 @ 0x00144360
extern "C" double __cdecl sin(double);

struct Holder_144360 {
    void FUN_001c3830(float a, float b);
};
Holder_144360 *FUN_001c3d90();

class BlurState {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual float vfunc_6();
    char pad04[0xc];
    float fadeInEnd;
    float fadeOutBegin;
    float fadeOutEnd;
    float valueB;
    float valueA;
};

namespace hulkfight {
namespace motion {

class MotionBlurAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int mode, float dt);

    char pad04[0x18];
    BlurState *state;
    float elapsed;
    float targetB;
    float targetA;
};

}
}

bool hulkfight::motion::MotionBlurAction::vfunc_5(int mode, float dt)
{
    if (mode != 1)
        return true;

    float t = dt + elapsed;
    elapsed = t;
    BlurState *s = state;
    float a = s->valueA;
    float b = s->valueB;

    if (t < s->fadeInEnd) {
        float fin = s->fadeInEnd;
        float den = fin - s->vfunc_6();
        float r = (elapsed - state->vfunc_6()) / den;
        if (b > targetB)
            b = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (b - targetB) * 0.5f + targetB;
        else
            b = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (targetB - b) * 0.5f + b;
        if (a > targetA)
            a = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (a - targetA) * 0.5f + targetA;
        else
            a = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (targetA - a) * 0.5f + a;
    } else if (t > s->fadeOutBegin) {
        float r = (t - s->fadeOutBegin) / (s->fadeOutEnd - s->fadeOutBegin);
        if (b > targetB)
            b = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (b - targetB) * 0.5f + targetB;
        else
            b = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (targetA - b) * 0.5f + b;
        if (a > targetA)
            a = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (a - targetA) * 0.5f + targetA;
        else
            a = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (targetA - a) * 0.5f + a;
    }
    FUN_001c3d90()->FUN_001c3830(b, a);
    return true;
}
