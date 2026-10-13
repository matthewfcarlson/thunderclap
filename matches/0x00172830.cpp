struct Vec {
    float x, y, z;
    float elapsed;
    float FUN_0022d110();
    void FUN_00011140(float);
};
struct Body {
    void FUN_00035760(Vec*);
};
struct Actor {
    Body* FUN_00059a30();
};
struct Handle {
    Actor* FUN_000592a0();
};
struct Source {
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
    Source* source;
    Handle* handle;
    Vec momentum;
};
bool MomentumXZAddAction::vfunc_5(int flag, float dt) {
    if (flag)
        return true;
    if (!handle)
        return false;
    Actor* actor = handle->FUN_000592a0();
    if (!actor)
        return false;
    Body* body = actor->FUN_00059a30();
    if (!body)
        return false;
    float rate = source->rate;
    if (rate >= 0.0f) {
        float duration = source->v7();
        if (duration >= 0.0f) {
            float remaining = duration - momentum.elapsed;
            if (remaining <= 0.0f) {
                momentum.FUN_0022d110();
                momentum.FUN_00011140(rate);
            } else {
                float current = momentum.FUN_0022d110();
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
