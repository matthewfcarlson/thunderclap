class FEDoAction {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class FEDoAnimation : public FEDoAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_5();
    char pad[0x30];
    void* mTarget;
};
void FEDoAnimation::vfunc_2() {
    if (mTarget) {
        ((FEDoAction*)mTarget)->f2();
    }
}