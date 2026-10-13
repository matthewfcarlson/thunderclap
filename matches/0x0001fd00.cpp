struct Angle {
    float FUN_000354c0();
    void FUN_00221d20(float);
};
struct Link2 {
    Angle* FUN_00059a30();
};
struct Link1 {
    Link2* FUN_000592a0();
};
struct Settings {
    char pad[20];
    float speed;
    float offset;
};
struct Destination {
    char pad[24];
    Angle angle;
};
float __cdecl FUN_00224fc0(float, float);
struct COrientTargetAction {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float);
    virtual void vfunc_8();
    char pad[24];
    Link1* source;
    Settings* settings;
    Angle* target;
    Destination* destination;
};
bool COrientTargetAction::vfunc_7(float dt) {
    if (!destination)
        return false;
    float current = source->FUN_000592a0()->FUN_00059a30()->FUN_000354c0();
    float desired = target->FUN_000354c0();
    desired = desired + settings->offset;
    if (settings->speed < 0.0f)
        current = desired;
    else {
        float delta = FUN_00224fc0(current, desired);
        float step = dt * settings->speed;
        union {
            float f;
            unsigned int u;
        } absolute;
        absolute.f = delta;
        absolute.u &= 0x7fffffff;
        if (absolute.f <= step)
            current = desired;
        else if (delta < 0.0f)
            current -= step;
        else
            current += step;
    }
    destination->angle.FUN_00221d20(current);
    return true;
}