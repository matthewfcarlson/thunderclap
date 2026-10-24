extern "C" {
typedef float(__stdcall* TimeFn)();
extern TimeFn GetTime;
}
class Part {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void SetTime(float, int);
};
class FEParticleAnimation {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad[0x60];
    Part* particle;
};
void FEParticleAnimation::vfunc_2() {
    if (particle)
        particle->SetTime(GetTime() * 1000.0f, 0);
}