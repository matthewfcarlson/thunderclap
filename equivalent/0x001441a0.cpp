// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// hulkfight::motion::SlowMotionAction::vfunc_5 @ 0x001441a0
extern "C" double __cdecl sin(double);

class Clock {
public:
    void FUN_00086100(float v);
};

struct Manager {
    char pad0[0x58];
    Clock *clock;
};
extern Manager *DAT_004dd700;

class Curve {
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
    float target;
    char active;
};

class SlowMotionAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual char vfunc_5(int mode, float dt);

    char pad04[0x18];
    Curve *curve;
    float base;
    float elapsed;
};

char SlowMotionAction::vfunc_5(int mode, float dt)
{
    if (mode != 1 && curve->active == 0)
        return 1;

    float t = dt + elapsed;
    elapsed = t;
    Curve *c = curve;
    float val = c->target;

    if (t < c->fadeInEnd) {
        float end = c->fadeInEnd;
        float den = end - c->vfunc_6();
        c = curve;
        float r = (elapsed - c->vfunc_6()) / den;
        if (val > base)
            val = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (val - base) * 0.5f + base;
        else
            val = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (base - val) * 0.5f + val;
    } else if (t > c->fadeOutBegin) {
        float r = (t - c->fadeOutBegin) / (c->fadeOutEnd - c->fadeOutBegin);
        if (val > base)
            val = (sin((0.5f - r) * 3.14159265f) + 1.0f) * (val - base) * 0.5f + base;
        else
            val = (sin((r - 0.5f) * 3.14159265f) + 1.0f) * (base - val) * 0.5f + val;
    }
    DAT_004dd700->clock->FUN_00086100(val);
    return 1;
}
