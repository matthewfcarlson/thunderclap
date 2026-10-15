// Same code shape as 0x000e45c0 (propagated; names are from that function)
class FEMenuBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual FEMenuBase* vfunc_8();
};
FEMenuBase* FEMenuBase::vfunc_8() {
    return (FEMenuBase*)((char*)this + 8);
}