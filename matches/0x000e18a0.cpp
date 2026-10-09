class FEDoAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class Component {
  public:
    virtual void f0();
    virtual void f1(FEDoAction*);
};
class FEDoParticleSystem : public FEDoAction {
    char pad[0x34 - sizeof(FEDoAction)];

  public:
    Component* mComponent;
    int mState;
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_5();
};
void FEDoParticleSystem::vfunc_1() {
    if (mComponent) {
        mComponent->f1(this);
        mState = 1;
    }
}
