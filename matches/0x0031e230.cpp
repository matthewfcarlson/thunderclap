typedef unsigned int u32;
extern u32 g_value;
class pddiDevice {
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
    virtual void vfunc_13(u32);
};
void pddiDevice::vfunc_13(u32 value) {
    g_value = value;
}