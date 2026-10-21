#include "compat/ptr.h"
struct Vec_172830 {
    float x, y, z;
    float elapsed;
    float FUN_0022d110();
    void FUN_00011140(float);
};
struct Body_172830 {
    void FUN_00035760(Vec_172830*);
};
struct Actor_172830 {
    Body_172830* FUN_00059a30();
};
struct Handle_172830 {
    Actor_172830* FUN_000592a0();
};
struct Source_172830 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float v7();
    char pad[16];
    float rate;
};
namespace hulkfight {
namespace motion {
struct MomentumXZAddAction {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool vfunc_5(int, float);
    char pad[24];
    Source_172830* source;
    Handle_172830* handle;
    Vec_172830 momentum;
};
bool MomentumXZAddAction::vfunc_5(int flag, float dt) {
    if (flag)
        return true;
    if (!handle)
        return false;
    Actor_172830* actor = handle->FUN_000592a0();
    if (!actor)
        return false;
    Body_172830* body = actor->FUN_00059a30();
    if (!body)
        return false;
    hulk_freg rate = source->rate;
    if (rate >= 0.0f) {
        hulk_freg duration = source->v7();
        if (duration >= 0.0f) {
            hulk_freg remaining = duration - momentum.elapsed;
            if (remaining <= 0.0f) {
                momentum.FUN_0022d110();
                momentum.FUN_00011140(rate);
            } else {
                hulk_freg current = momentum.FUN_0022d110();
                momentum.FUN_00011140(current + (rate - current) * (dt / remaining));
            }
        }
    }
    momentum.elapsed += dt;
    body->FUN_00035760(&momentum);
    return true;
}
} // namespace motion
} // namespace hulkfight
