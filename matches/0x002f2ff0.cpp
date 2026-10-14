typedef unsigned int u32_2f2ff0;
struct Obj_2f2ff0 {
    virtual void a();
    virtual void b();
    virtual u32_2f2ff0 c();
    virtual void d();
    virtual u32_2f2ff0 e();
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
};
namespace physics {
class CollisionCylinder : public Obj_2f2ff0 {
  public:
    char pad[0x40];
    float x;
    void vfunc_11(void*);
};
} // namespace physics
struct Helper_2f2ff0 {
    void first(void*, void*);
    void second(u32_2f2ff0, u32_2f2ff0);
};
void physics::CollisionCylinder::vfunc_11(void* p) {
    Helper_2f2ff0* h = (Helper_2f2ff0*)p;
    h->first(&x, &x);
    u32_2f2ff0 a = e();
    h->second(e(), a);
}
