// STATUS: equivalent (tools/equiv.py level 3: 17318 inputs, branch coverage 6/6)
// pure3d::Vector2DOFChannel::vfunc_4 @ 0x0028a630
#include "compat/ptr.h"
union OutSlot;
struct Key2 {
    float a;
    float b;
};

class Vector2DOFChannel {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(union TimeArg targ, union OutSlot slot);
    virtual void vfunc_5();
    char FUN_00289f80(float t, int *indexA, int *indexB);

    void *keyData;
    char pad08[0x14 - 0x8];
    short *keyTimes;
    int axisMode;
    float base[3];
    Key2 *values;
};

union TimeArg {
    float t;
    int span;
};

union OutSlot {
    float *out;
    int index;
};

struct Frame {
    int indexB;
    int axes[3][2];
};

void Vector2DOFChannel::vfunc_4(TimeArg targ, OutSlot slot)
{
    Frame f;
    float *out = slot.out;
    f.axes[0][0] = 1;
    f.axes[0][1] = 2;
    f.axes[1][0] = 0;
    f.axes[1][1] = 2;
    f.axes[2][0] = 0;
    f.axes[2][1] = 1;

    out[0] = base[0];
    out[1] = base[1];
    out[2] = base[2];

    if (FUN_00289f80(targ.t, &slot.index, &f.indexB) && keyData != 0) {
        int indexA = slot.index;
        slot.index = keyTimes[indexA];
        hulk_freg d = targ.t - (float)slot.index;
        if (d != 0.0f) {
            targ.span = keyTimes[f.indexB] - keyTimes[indexA];
            int span = targ.span;
            Key2 *v = values;
            out[f.axes[axisMode][0]] = (v[f.indexB].a - v[indexA].a) * (d / (float)span) + v[indexA].a;
            out[f.axes[axisMode][1]] = (v[f.indexB].b - v[indexA].b) * (d / (float)span) + v[indexA].b;
            return;
        }
        out[f.axes[axisMode][0]] = values[indexA].a;
        out[f.axes[axisMode][1]] = values[indexA].b;
        return;
    }
    out[f.axes[axisMode][0]] = values[slot.index].a;
    out[f.axes[axisMode][1]] = values[slot.index].b;
}
