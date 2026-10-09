// Same code shape as 0x000e45c0 (propagated; names are from that function)
class FEContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual FEContainer* vfunc_8();
};
FEContainer* FEContainer::vfunc_8() {
    return (FEContainer*)((char*)this + 8);
}