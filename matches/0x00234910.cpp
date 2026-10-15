namespace fight {
class Provider {
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
    virtual char read(int, int, int*);
};
class ParamValueInt {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual char vfunc_5(int, int, Provider*);
    virtual void set(int, int);
    int pad;
    int x;
    int y;
};
char ParamValueInt::vfunc_5(int a, int b, Provider* p) {
    int n = 0;
    int xx = x;
    int yy = y;
    char ok = p->read(xx, yy, &n);
    if (ok)
        set(a, n);
    return ok;
}
} // namespace fight