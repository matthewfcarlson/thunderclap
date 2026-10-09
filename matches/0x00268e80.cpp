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
    virtual void f8(int);
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    char pad[0x2c - 4];
    int a;
    int b;
};
void ControllerInputPointXBox::f8(int x) {
    if (a == x) {
        a = 0;
        b = 0;
    }
}