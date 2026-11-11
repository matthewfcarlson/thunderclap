// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00319580..0x00319670 (kind game, layer engine, confidence high), dominant class physics::SimpleFilter1D
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_fda0535d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fda0535d {} using namespace fn_fda0535d;
#include "engine/physics.h"


// 0x00319580 physics::SimpleFilter1D::vfunc_2 (4 B): matches/0x00319580.cpp
// sym: ?vfunc_2@SimpleFilter1D@physics@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg physics::SimpleFilter1D::vfunc_2() {
    return this->f_0c;
}


// 0x00319590 physics::SimpleFilter1D::vfunc_0 (54 B): matches/0x00319590.cpp [wrapped: conflict: physics::Filter1D; physics::SimpleFilter1D]
// sym: ?vfunc_0@SimpleFilter1D@physics@fn_00319590@@UAE_NHMH@Z
namespace fn_00319590 {
namespace physics {
class Filter1D {
  public:
    virtual bool vfunc_0(int, float, int);
    virtual void vfunc_1();
    virtual void vfunc_2();
};
class SimpleFilter1D : public Filter1D {
  public:
    float scale;
    char pad[4];
    int value;
    int state;
    virtual bool vfunc_0(int, float, int);
};
bool SimpleFilter1D::vfunc_0(int v, float f, int) {
    value = v;
    if (f <= 0.0f)
        return false;
    state = 0;
    scale = 1.0f / f;
    return true;
}
} // namespace physics
} // namespace fn_00319590


// 0x003195d0 physics::SimpleFilter1D::vfunc_1 (150 B): equivalent/0x003195d0.cpp [wrapped: conflict: physics::Filter1D; physics::SimpleFilter1D]
// sym: ?vfunc_1@SimpleFilter1D@physics@fn_003195d0@@UAEMMM@Z
namespace fn_003195d0 {
// STATUS: equivalent (tools/equiv.py level 3: 20003 inputs, branch coverage 8/8)
// physics::SimpleFilter1D::vfunc_1 @ 0x003195d0
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
} // namespace fn_003195d0

