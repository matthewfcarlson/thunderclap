class ControllerInputPointXBox {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void vfunc_7(int a, int b);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    char pad[0x28];
};
void ControllerInputPointXBox::vfunc_7(int a, int b) {
    if (*(int*)((char*)this + 0x2c) == 0) {
        *(int*)((char*)this + 0x30) = b;
        *(int*)((char*)this + 0x2c) = a;
    }
}