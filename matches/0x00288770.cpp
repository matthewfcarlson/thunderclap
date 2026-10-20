#include "compat/ptr.h"
#include "gen/pure3d.h"

extern int EntityType, CompositeType, PoseType;
class Result_288770 {
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
    virtual unsigned int run();
};
extern Result_288770* __cdecl resolve(void*, int, const void*, const void*, int);
struct PoseAnimationController_nv_288770 {
    void set(unsigned int);
};

void pure3d::PoseAnimationController::vfunc_5(void* __p0) { void * arg = (void *)__p0;

    Result_288770* p = resolve(arg, 0, &EntityType, &CompositeType, 0);
    if (p) {
        ((PoseAnimationController_nv_288770*)this)->set(p->run());
    } else {
        hulk_uintptr x = (hulk_uintptr)resolve(arg, 0, &EntityType, &PoseType, 0);
        ((PoseAnimationController_nv_288770*)this)->set(x);
    }
}
