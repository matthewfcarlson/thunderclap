extern const float g_zero;
struct MotionState {
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
struct Ret {
    void f();
};
void* __stdcall FUN_001c3d90(void*, void*);
class MotionBlurAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool vfunc_3(int a, int b);
    char pad0[0x1c - 4];
    MotionState* state;
    float amount;
};
bool MotionBlurAction::vfunc_3(int a, int b) {
    amount = state->f6();
    if (state->value < g_zero)
        return false;
    Ret* r = (Ret*)FUN_001c3d90((char*)this + 0x24, (char*)this + 0x28);
    r->f();
    return true;
}
