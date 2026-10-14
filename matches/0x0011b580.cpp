void* operator new(unsigned int);
extern "C" void _ReadWriteBarrier();
struct B_11b580 {
    B_11b580() throw();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual B_11b580* f5();
    int m4, m8;
};
struct S1_11b580 {
    int a;
    float b;
    int c;
    S1_11b580() throw() {
        a = 0;
        _ReadWriteBarrier();
        b = -1.0f;
        _ReadWriteBarrier();
        c = 0;
    }
};
struct S2_11b580 {
    int d;
    int e;
    float f;
    float g;
    S2_11b580() throw() {
        d = 0;
        e = 0;
        f = -1.0f;
        g = 1.0f;
    }
};
struct T_11b580 : B_11b580, S1_11b580 {
    S2_11b580 s2;
    T_11b580() throw() {}
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual B_11b580* f5();
};
struct Fac_11b580 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual B_11b580* f5();
};
B_11b580* Fac_11b580::f5() {
    return new T_11b580;
}
