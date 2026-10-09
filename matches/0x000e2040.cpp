class Child {
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
    virtual bool f11(int, int);
};
class FELayout {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};
class SingleLayout : public FELayout {
  public:
    char pad[0x40];
    Child* mChild;
    bool vfunc_6(int a, int b);
};
bool SingleLayout::vfunc_6(int a, int b) {
    if (!mChild)
        return false;
    return mChild->f11(a, b);
}