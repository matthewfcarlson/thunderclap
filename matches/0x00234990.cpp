namespace fight {
class Source {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual char get(int, int, int*);
};
class ParamValue {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual char f5(int, int, Source*);
    virtual void f6(int, int);
    int pad;
};
class ParamValueFloat : public ParamValue {
  public:
    int x;
    int y;
    virtual char f5(int, int, Source*);
};
char ParamValueFloat::f5(int a, int b, Source* src) {
    int xx = x;
    int yy = y;
    int value = 0;
    char ok = src->get(xx, yy, &value);
    if (ok)
        f6(a, value);
    return ok;
}
} // namespace fight