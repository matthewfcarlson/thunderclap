#include "compat/ptr.h"
typedef unsigned char u8_2f3030;
extern int vtable_2f3030;
struct Part_2f3030 {
    void init();
};
namespace physics {
struct CollisionCylinder {
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
    char pad[0x64 - 4];
    CollisionCylinder* vfunc_2(u8_2f3030);
    void base();
};
} // namespace physics
void cleanup(physics::CollisionCylinder*);
physics::CollisionCylinder* physics::CollisionCylinder::vfunc_2(u8_2f3030 flag) {
    *(hulk_intptr*)this = (hulk_intptr)&vtable_2f3030;
    ((Part_2f3030*)((char*)this + 0x64))->init();
    ((Part_2f3030*)((char*)this + 0x38))->init();
    base();
    if (flag & 1)
        cleanup(this);
    return this;
}