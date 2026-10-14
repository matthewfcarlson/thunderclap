class Thing_1c12f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual int get();
};
class Wrapper_1c12f0 {
  public:
    char pad[8];
    Thing_1c12f0* value;
};
int __fastcall FUN_001c12f0(Wrapper_1c12f0* self) {
    return self->value->get() + 0x20;
}