namespace physics {
class CollisionRay {
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
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void vfunc_18(unsigned int);
    char pad[0x7c];
};
void CollisionRay::vfunc_18(unsigned int value) {
    *(unsigned int*)((char*)this + 0x80) = value;
}
} // namespace physics