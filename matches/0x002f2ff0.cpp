#include "compat/ptr.h"
#include "gen/physics.h"
#include "gen/owners.h"

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
} // namespace physics
struct Helper_2f2ff0 {
};
void physics::CollisionCylinder::vfunc_11(void* __p0) { void * p = (void *)__p0;

    Helper_2f2ff0* h = (Helper_2f2ff0*)p;
    ((owners::M_22c3b0 *)h)->FUN_0022c3b0((float *)(&this->f_44), (float *)(&this->f_44));
    hulk_uintptr a = vfunc_4();
    ((owners::Mat_22c2b0 *)h)->FUN_0022c2b0((float *)(hulk_uintptr)(hulk_uintptr)(vfunc_4()), (float *)(hulk_uintptr)(hulk_uintptr)a);
}
