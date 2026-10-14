struct Inner_1c12c0 {
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
    virtual void target();
};
struct Wrapper_1c12c0 {
    int pad[2];
    Inner_1c12c0* ptr;
};
void __fastcall FUN_001c12c0(Wrapper_1c12c0* self) {
    self->ptr->target();
}
