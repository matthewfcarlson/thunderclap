class FEDoAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
};
class Other_e1830 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void vfunc_3();
};
class FEDoAnimation : public FEDoAction {
  public:
    virtual void vfunc_5();
    char pad[0x30];
    Other_e1830* mOther;
};
void FEDoAnimation::vfunc_5() {
    if (mOther)
        mOther->vfunc_3();
}