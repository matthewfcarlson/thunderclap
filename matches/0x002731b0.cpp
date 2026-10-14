struct A {
    virtual void f0();
    virtual void f1();
    virtual void f();
};
struct B {
    virtual void f();
};
struct C : A, B {
    C();
    void f();
};
C::C() {}
void C::f() {}
