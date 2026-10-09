struct TextWindow;
struct Sub {
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
    virtual void f15(float*, TextWindow*);
};
struct TextWindow {
    char pad[0x14];
    Sub* sub;
    float vfunc_9();
};
float TextWindow::vfunc_9() {
    char local[12];
    sub->f15((float*)local, this);
    return *(float*)local * 1.05f;
}