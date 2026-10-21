#include "compat/ptr.h"
struct Vec3_ecdf0 {
    int pad;
    float x;
    float y;
};
struct X_ecdf0 {
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
    virtual void p(Vec3_ecdf0*, void*);
};
struct TextWindow {
    char pad[20];
    X_ecdf0* obj;
    hulk_freg vfunc_8();
};
hulk_freg TextWindow::vfunc_8() {
    Vec3_ecdf0 v;
    obj->p(&v, this);
    return v.x * 1.05f;
}
