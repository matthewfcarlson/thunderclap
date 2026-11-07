#include "compat/ptr.h"
struct Angle_1fd00 {
    hulk_freg FUN_000354c0();
    void FUN_00221d20(float);
};
struct Link2_1fd00 {
    Angle_1fd00* FUN_00059a30();
};
struct Link1_1fd00 {
    Link2_1fd00* FUN_000592a0();
};
struct Settings_1fd00 {
    char pad[20];
    float speed;
    float offset;
};
struct Destination_1fd00 {
    char pad[24];
    Angle_1fd00 angle;
};
hulk_freg __cdecl FUN_00224fc0(float, float);
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
    Link1_1fd00* source;
    Settings_1fd00* settings;
    Angle_1fd00* target;
    Destination_1fd00* destination;
};
bool COrientTargetAction::vfunc_7(float dt) {
    if (!destination)
        return false;
    float current = source->FUN_000592a0()->FUN_00059a30()->FUN_000354c0();
    hulk_freg heading = target->FUN_000354c0();   // st0: added unrounded (clang would round a float local)
    float desired = heading + settings->offset;
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