class Child_e24a0 {
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
    virtual bool f11(int, int);
};
class VScroll {
  public:
    virtual void q0();
    char pad[0x240];
    Child_e24a0* child;
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual bool vfunc_6(int a, int b);
};
bool VScroll::vfunc_6(int a, int b) {
    if (child && child->f11(a, b))
        return true;
    return false;
}