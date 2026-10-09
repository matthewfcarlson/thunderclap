extern float gDelta;
class Thing {
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
void Thing::Set(float x) {
    gDelta = x;
    First();
    Second();
}
