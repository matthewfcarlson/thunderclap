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
    virtual char f10(int, int, int*);
};
class ParamValue {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual char v5(int, int, Reader*);
    virtual void v6(int, int);
    int unused;
    int a;
    int b;
};
class ParamValueColour : public ParamValue {
  public:
    virtual char v5(int, int, Reader*);
};
char ParamValueColour::v5(int x, int y, Reader* r) {
    int result;
    int aa = a;
    int bb = b;
    result = 0;
    char ok = r->f10(aa, bb, &result);
    if (ok)
        v6(x, result);
    return ok;
}
} // namespace fight