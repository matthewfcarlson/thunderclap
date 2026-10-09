class ControllerInputPointXBox {
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
    virtual void vfunc_10(void*, void*);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    char pad[8];
    int a;
    int b;
};
void ControllerInputPointXBox::vfunc_10(void* x, void* y) {
    a = (int)x;
    b = (int)y;
}