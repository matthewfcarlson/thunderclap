// Same code shape as 0x001fbfb0 (propagated; names are from that function)
typedef unsigned int uint;
extern "C" void __fastcall __security_check_cookie(uint);
extern "C" uint g_cookie;
class CLocator {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void vfunc_7(int);
    virtual void f8();
    virtual void f9();
    virtual void f10();
};
void CLocator::vfunc_7(int) {
    volatile uint t = g_cookie;
    __security_check_cookie(t);
}
