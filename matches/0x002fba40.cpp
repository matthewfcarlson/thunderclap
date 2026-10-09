typedef unsigned char byte;
class H1 {
  public:
    void f();
};
class H2 {
  public:
    void f();
};
class H3 {
  public:
    void f();
};
namespace physics {
class CollisionVolume {
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
};
class CollisionOBB : public CollisionVolume {
  public:
    virtual void v0();
    virtual void v1();
    virtual CollisionOBB* vfunc_2(byte);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    char pad[0x78];
};
} // namespace physics
void cleanup(physics::CollisionOBB*);
physics::CollisionOBB* physics::CollisionOBB::vfunc_2(byte flag) {
    CollisionOBB* self = this;
    *(unsigned long*)self = 0x4317dc;
    ((H1*)((char*)self + 0x7c))->f();
    ((H2*)((char*)self + 0x3c))->f();
    ((H3*)self)->f();
    if (flag & 1)
        cleanup(self);
    return self;
}