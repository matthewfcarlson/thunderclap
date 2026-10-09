class DrawableContainer {
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
    virtual int vfunc_18(int);
};
class PolySkin : public DrawableContainer {
  public:
    char pad[0x6c - 4];
    int a;
    int b;
    virtual int vfunc_18(int);
};
int PolySkin::vfunc_18(int n) {
    int x = a;
    if (x) {
        if (n == 0)
            return x;
        --n;
    }
    if (b) {
        if (n == 0 || (n == 1 && x))
            return b;
        --n;
    }
    return DrawableContainer::vfunc_18(n);
}