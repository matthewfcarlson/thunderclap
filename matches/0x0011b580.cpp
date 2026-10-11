void* operator new(unsigned int);
extern "C" void _ReadWriteBarrier();
struct B {
    B() throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual B* f5();
    int m4, m8;
};
struct S1 {
    int a;
    float b;
    int c;
    S1() throw() {
        a = 0;
        _ReadWriteBarrier();
        b = -1.0f;
        _ReadWriteBarrier();
        c = 0;
    }
};
struct S2 {
    int d;
    int e;
    float f;
    float g;
    S2() throw() {
        d = 0;
        e = 0;
        f = -1.0f;
        g = 1.0f;
    }
};
struct T : B, S1 {
    S2 s2;
    T() throw() {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual B* f5();
};
struct Fac {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual B* f5();
};
B* Fac::f5() {
    return new T;
}
