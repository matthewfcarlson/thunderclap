class d3dContext {
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
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual int vfunc_30(int, int, int, int, int);
    char p0[0x15c];
    int fallback;
    char p1[0xa0];
    int result;
    char p2[0x20c];
    unsigned char flag;
    void fix();
};
class Worker_321860 {
  public:
    int run(int, int, int, int, int);
};
int d3dContext::vfunc_30(int a, int b, int c, int d, int e) {
    if (!a)
        a = fallback;
    if (flag)
        fix();
    ((Worker_321860*)result)->run(b, c, a, d, e);
    return result;
}