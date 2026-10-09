typedef unsigned int u32;
extern int gState;
class B {
  public:
    virtual u32 a0();
    virtual u32 a1();
    virtual u32 a2();
    virtual u32 a3();
    virtual u32 a4();
    virtual u32 a5();
    virtual u32 a6();
    virtual u32 a7();
    virtual u32 a8();
    virtual u32 a9();
    virtual u32 a10();
    virtual u32 a11();
    virtual u32 a12();
    virtual u32 a13();
    virtual u32 a14();
    virtual u32 a15(u32, u32, u32, u32, u32);
};
class A {
  public:
    char pad[0x40];
    B* p;
    u32 f(u32 a, u32 b, u32 c, u32 d);
};
u32 A::f(u32 a, u32 b, u32 c, u32 d) {
    if (p) {
        gState = 0;
        return p->a15(a, b, 2, c, d);
    }
    return 0;
}
