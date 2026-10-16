struct Vec {
    int a, b, c;
};
class SingleLayout {
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
    virtual Vec* vfunc_15(Vec*, int);
    char pad[0x24];
    Vec value;
};
Vec* SingleLayout::vfunc_15(Vec* out, int) {
    *out = value;
    return out;
}