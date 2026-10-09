class FEDoAction {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class Obj {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(float);
    virtual float g();
};
class FEDoAnimation : public FEDoAction {
  public:
    char pad[0x30];
    Obj* mObj;
    char pad2[4];
    float mValue;
    void helper();
    void vfunc_3();
};
void FEDoAnimation::vfunc_3() {
    if (mObj) {
        if (mValue < 0.0f) {
            mValue = mObj->g();
            helper();
            return;
        }
        if (mValue > -1.0f)
            mObj->e(mValue);
        else
            mObj->e(0.0f);
    }
}
