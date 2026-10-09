class Pad {
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
    virtual void f19(unsigned int);
};
class ControllerSystemXBox {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(unsigned int);
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    char pad[0x20 - 4];
};
void ControllerSystemXBox::f8(unsigned int arg) {
    char* p = (char*)this + 0x20;
    for (int i = 0; i < 4; i++, p += 0x4a0) {
        if (p[0x49e])
            ((Pad*)p)->f19(arg);
    }
}