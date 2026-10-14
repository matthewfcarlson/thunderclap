extern "C" char DAT_004317dc[];
typedef unsigned char byte_2fba40;
class H1 {
  public:
    void f();
};
class H2_2fba40 {
  public:
    void f();
};
class H3_2fba40 {
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
    virtual CollisionOBB* vfunc_2(byte_2fba40);
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
physics::CollisionOBB* physics::CollisionOBB::vfunc_2(byte_2fba40 flag) {
    CollisionOBB* self = this;
    *(unsigned long*)self = ((int)DAT_004317dc);
    ((H1*)((char*)self + 0x7c))->f();
    ((H2_2fba40*)((char*)self + 0x3c))->f();
    ((H3_2fba40*)self)->f();
    if (flag & 1)
        cleanup(self);
    return self;
}