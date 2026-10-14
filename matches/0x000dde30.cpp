extern float gDelta;
class Thing_dde30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void First();
    virtual void f8();
    virtual void Second();
    void Set(float x);
};
void Thing_dde30::Set(float x) {
    gDelta = x;
    First();
    Second();
}
