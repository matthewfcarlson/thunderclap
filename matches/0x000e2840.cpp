class Outer_e2840;
class Inner_e2840 {
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
    virtual void invoke(Outer_e2840*);
};
class Outer_e2840 {
  public:
    char pad[0x14];
    Inner_e2840* p;
    void call();
};
void Outer_e2840::call() {
    Outer_e2840* self = this;
    p->invoke(self);
}