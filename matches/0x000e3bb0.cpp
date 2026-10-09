// Same code shape as 0x000e3e20 (propagated; names are from that function)
class FEControl {
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
};
class FEObject {};
class IValueChangedReceiver {};
class IValueChangedSender {};
class TextTable : public FEControl,
                  public FEObject,
                  public IValueChangedReceiver,
                  public IValueChangedSender {
  public:
    virtual char vfunc_10(int, int);
};
char TextTable::vfunc_10(int x, int y) {
    if (x)
        return x == 4;
    return 1;
}