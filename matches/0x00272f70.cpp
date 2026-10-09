// Same code shape as 0x0026f130 (propagated; names are from that function)
class X {
  public:
    virtual void f();
    virtual void g();
    int n;
};
class Drive {
  public:
    virtual void vfunc_0();
    char pad[8];
    X x;
};
void Drive::vfunc_0() {
    X* p = &x;
    p->f();
    ++p->n;
    p->g();
}
