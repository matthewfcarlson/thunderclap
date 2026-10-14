class A {
  public:
    virtual void f();
    virtual ~A();
};
class B {
  public:
    virtual void f();
    virtual ~B();
};
class C : public A, public B {
  public:
    virtual void f();
    virtual ~C();
    int mX;
};
void C::f() {
    mX = 0;
}
C::~C() {}
