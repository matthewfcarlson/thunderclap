class pddiObject {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class pddiPrimBuffer : public pddiObject {
  public:
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};
class d3dPrimBuffer : public pddiPrimBuffer {
  public:
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual bool vfunc_10(int);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
};
bool d3dPrimBuffer::vfunc_10(int value) {
    return value == 0x20001;
}