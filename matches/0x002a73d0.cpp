extern "C" void _ReadWriteBarrier();
struct Base_2a73d0 {
    virtual void f0();
    Base_2a73d0();
    char pad[0x3c];
};
struct PC_2a73d0 : Base_2a73d0 {
    PC_2a73d0();
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
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void vfunc_23();
    char m40;
    float m44;
    float m48;
    int m4c;
    int m50;
    int m54;
};
PC_2a73d0::PC_2a73d0() {
    m40 = 1;
    m44 = 100.0f;
    m48 = 30.0f;
    m4c = 0;
    _ReadWriteBarrier();
    m50 = 0;
    m54 = 0;
    vfunc_23();
}
