class X_26f130 {
  public:
    virtual void f();
    virtual void g();
    int n;
};
class Drive {
  public:
    virtual void vfunc_0();
    char pad[8];
    X_26f130 x;
};
void Drive::vfunc_0() {
    X_26f130* p = &x;
    p->f();
    ++p->n;
    p->g();
}
