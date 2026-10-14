class Base_e18d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
class FEDoAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class Inner_e18d0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
};
class FEDoParticleSystem : public FEDoAction {
  public:
    char pad[0x34 - sizeof(FEDoAction)];
    Inner_e18d0* mInner;
    virtual void p0();
    virtual void p1();
    virtual void p2();
    void vfunc_5();
};
void FEDoParticleSystem::vfunc_5() {
    mInner->d();
}