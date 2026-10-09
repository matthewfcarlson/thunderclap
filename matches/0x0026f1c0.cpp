class Drive {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Drive* f4();
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
};
class XboxDrive : public Drive {
  public:
    char pad[0xc4 - sizeof(Drive)];
    Drive* vfunc_4();
};
Drive* XboxDrive::vfunc_4() {
    return (Drive*)((char*)this + 0xc4);
}