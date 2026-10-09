namespace pure3d {
class AnimationFrameController {
  public:
    float vfunc_20();
};
class ParticleController {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual float vfunc_20();
    virtual void f21();
    char pad0[0x1c];
    int field20;
    char pad24[8];
    float field2c;
    float field30;
    char pad34[12];
    unsigned char field40;
};
const float gMaxFloat = 3.402823466e+38F;
float ParticleController::vfunc_20() {
    if (field20 == 0) {
        if (field40 == 1)
            return gMaxFloat;
        return field30 - field2c;
    }
    return ((AnimationFrameController*)this)->vfunc_20();
}
} // namespace pure3d