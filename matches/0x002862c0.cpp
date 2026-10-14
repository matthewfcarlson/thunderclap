class Sub_2862c0 {
  public:
    void invoke();
};
class BlendFrameController {
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
    char pad4[0x18 - 4];
    float m18;
    char pad1c[4];
    int m20;
    int m24;
    unsigned int m28;
    Sub_2862c0 sub;
};
void BlendFrameController::f23() {
    while (m28 > 1)
        f29();
    if (m28 == 1)
        sub.invoke();
    m20 = 0;
    m24 = 0;
    m18 = 1.0f;
}