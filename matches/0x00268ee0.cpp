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
    virtual void f10();
    virtual void vfunc_11(unsigned long*, unsigned long*);
    virtual void f12();
    virtual void f13();
    virtual void f14();
    unsigned char pad[0x0c - 4];
    unsigned long mA;
    unsigned long mB;
};
void ControllerInputPointXBox::vfunc_11(unsigned long* a, unsigned long* b) {
    if (a)
        *a = mA;
    if (b)
        *b = mB;
}
