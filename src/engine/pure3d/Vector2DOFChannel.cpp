// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028a5b0..0x0028a780 (kind game, layer engine, confidence medium), dominant class pure3d::Vector2DOFChannel
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_ff1c9535 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff1c9535 {} using namespace fn_ff1c9535;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_ff1c9535 {
namespace pure3d {
class Vector2DOFChannel {
public:
    char pad00[0x14];
    short* times;
    int axis;
    int base[3];
    int (*values)[2];
    void vfunc_3(int index, float* time, int* out);
};
}
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


// 0x0028a5b0 pure3d::Vector2DOFChannel::vfunc_3 (128 B): matches/0x0028a5b0.cpp
// sym: ?vfunc_3@Vector2DOFChannel@pure3d@fn_ff1c9535@@QAEXHPAMPAH@Z
// pure3d::Vector2DOFChannel::vfunc_3 @ 0x0028a5b0
// 0x0028a5b0: Vector2DOFChannel::vfunc_3: read key `index`: its time, and a vector with two components keyed
namespace pure3d {
void Vector2DOFChannel::vfunc_3(int index, float* time, int* out)
{
    int other[3][2] = { { 1, 2 }, { 0, 2 }, { 0, 1 } };
    *time = (float)times[index];
    out[0] = base[0];
    out[1] = base[1];
    out[2] = base[2];
    out[other[axis][0]] = values[index][0];
    out[other[axis][1]] = values[index][1];
}
}


// 0x0028a630 pure3d::Vector2DOFChannel::vfunc_4 (321 B): equivalent/0x0028a630.cpp
// sym: ?vfunc_4@Vector2DOFChannel@fn_ff1c9535@@UAEXTTimeArg@2@TOutSlot@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 17318 inputs, branch coverage 6/6)
// pure3d::Vector2DOFChannel::vfunc_4 @ 0x0028a630
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

} // namespace fn_ff1c9535
