class A_2777e0 {
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
};

class B_2777e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class C_2777e0 : public A_2777e0, public B_2777e0 {
  public:
    virtual void f2();
    C_2777e0();
};

C_2777e0::C_2777e0() {}
