struct V {
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17(int, int);
};
struct G {
    void a();
    void b(int, int, int);
};
struct T {
    V* p;
    void f(int, int, int);
};
extern G glob;
void T::f(int a, int b, int c) {
    glob.a();
    glob.b(a, b, c);
    p->x17(0, (int)&glob);
}