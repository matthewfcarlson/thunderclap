class A {
  public:
    virtual void f();
};

class B {
  public:
    virtual void f();
};

class C : public A, public B {
  public:
    virtual void f();
};

void C::f() {}

C gC;
