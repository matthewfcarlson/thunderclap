// Same code shape as 0x0031e230 (propagated; names are from that function)
typedef unsigned int u32_31ed10;
extern u32_31ed10 g_value_31ed10;
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
    virtual void vfunc_13(u32_31ed10);
};
void pddiDevice::vfunc_13(u32_31ed10 value) {
    g_value_31ed10 = value;
}