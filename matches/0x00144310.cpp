#include "gen/hulkfight.h"

extern const float g_zero_144310;
struct MotionState_144310 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual float f6();
    char pad[0x1c - 4];
    float value;
};
struct Ret_144310 {
    void f();
};
void* __stdcall FUN_001c3d90(void*, void*);

bool hulkfight::motion::MotionBlurAction::vfunc_3(int a, int b) {
    this->f_20 = (*(MotionState_144310 * *)&this->f_1c)->f6();
    if ((*(MotionState_144310 * *)&this->f_1c)->value < g_zero_144310)
        return false;
    Ret_144310* r = (Ret_144310*)FUN_001c3d90((char*)this + 0x24, (char*)this + 0x28);
    r->f();
    return true;
}
