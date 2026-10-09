class MapThing {
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
    virtual int vfunc_13();
    virtual int vfunc_14();
};
class Helper {
  public:
    int go();
};
int MapThing::vfunc_14() {
    int x = vfunc_13();
    if (x)
        return ((Helper*)x)->go();
    return 0;
}