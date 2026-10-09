class MultiController {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void vfunc_6(float, char);
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    char pad10[0x18 - 4];
    float value;
    char pad1c[4];
    float scale;
};
void MultiController::vfunc_6(float x, char update) {
    value = x * scale + value;
    if (update == 1)
        g();
}