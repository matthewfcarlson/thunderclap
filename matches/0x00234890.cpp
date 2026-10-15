namespace fight {
class Reader {
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
    virtual char Read(int, int, int*);
};
class ParamValue {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual char f5(int, int, Reader*);
    virtual void Set(int, int);
    int pad;
    int a;
    int b;
};
class ParamValueBool : public ParamValue {
  public:
    virtual char vfunc_5(int x, int y, Reader* r);
};
char ParamValueBool::vfunc_5(int x, int y, Reader* r) {
    int val;
    *(char*)&val = 0;
    int aa = a;
    int bb = b;
    char ok = r->Read(aa, bb, &val);
    if (ok)
        Set(x, val);
    return ok;
}
} // namespace fight