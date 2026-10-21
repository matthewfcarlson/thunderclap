// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 28/28)
// pure3d::AnimationFrameController::vfunc_20 @ 0x00284b70
#include "compat/ptr.h"
struct Status_284b70 {
    char pad[0x18];
    char state;
};

class AnimController {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual float getTime();
    virtual void v14();
    virtual void getRange(float *start, float *end);
    virtual void v16();
    virtual int getMode();
    virtual void v18();
    virtual unsigned getCycles();
    virtual hulk_freg vfunc_20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual Status_284b70 *getStatus();
    virtual void v26();
};

hulk_freg AnimController::vfunc_20()
{
    float start;
    float end;
    getRange(&start, &end);
    float dur = end - start;
    unsigned cycles = getCycles();
    float t = getTime();

    switch (getMode()) {
    case 0: {
        Status_284b70 *s = getStatus();
        if (s == 0)
            return 0.0f;
        if (s->state != 1)
            return dur;
        return 3.4028235e+38f;
    }
    case 2:
        if (cycles == 0)
            return 3.4028235e+38f;
        return (float)cycles * dur - (t - start);
    case 3:
        if (cycles == 0)
            return 3.4028235e+38f;
        return (float)cycles * dur - (end - t);
    case 4:
        if (cycles == 0)
            return 3.4028235e+38f;
        {
            float v = (float)cycles * dur;
            return (v + v) - (t - start);
        }
    case 5:
        if (cycles == 0)
            return 3.4028235e+38f;
        {
            float v = (float)cycles * dur;
            return (v + v) - (end - t);
        }
    default:
        return 0.0f;
    }
}
