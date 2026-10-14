class Foo_2773f0 {
  public:
    virtual void f();
};
class core_CementLibrary {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void vfunc_5(Foo_2773f0*, int);
    virtual void g();
    virtual void h();
    virtual void i();
    char pad[0x6c - 4];
    Foo_2773f0* p;
    int q;
};
void core_CementLibrary::vfunc_5(Foo_2773f0* param_2, int param_3) {
    p = param_2;
    q = param_3;
    param_2->f();
}