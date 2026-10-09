// Same code shape as 0x0026f190 (propagated; names are from that function)
namespace core {
class Drive {
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
    virtual void f19();
    virtual void f20();
    virtual void f21();
    char pad[0x1d4 - 4];
    int member;
};
void __cdecl helper(int);
class XboxDrive : public Drive {
  public:
    void vfunc_0_adjc();
};
void XboxDrive::vfunc_0_adjc() {
    helper(member);
}
} // namespace core