// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::SlowMotionAction::vfunc_3 @ 0x00144150
struct MotionSource {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual float vfunc_6();
    char pad[0x1c - 4];
    float value;
};
extern const float DAT_003f3358;
extern const float DAT_003f32dc;
struct SlowMotionAction {
    char pad[0x1c];
    MotionSource *source;
    float factor;
    float measured;
    bool vfunc_3(int a, int b);
};
bool SlowMotionAction::vfunc_3(int a, int b) {
    measured = source->vfunc_6();
    factor = 1.0f;
    float value = source->value;
    if (!(value <= DAT_003f3358) && value != DAT_003f32dc)
        return true;
    return false;
}