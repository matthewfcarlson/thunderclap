#include "gen/global.h"

struct Obj_e46b0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(unsigned int, int);
};
struct Factory_e46b0 {
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
    virtual Obj_e46b0* make(const char*, int);
};
extern Factory_e46b0* glob_e46b0;

void FEThingsBase::vfunc_66() {
    if (!(*(Obj_e46b0 * *)&this->f_17fc)) {
        (*(Obj_e46b0 * *)&this->f_17fc) = glob_e46b0->make("simple", 0);
        (*(Obj_e46b0 * *)&this->f_17fc)->a();
        (*(Obj_e46b0 * *)&this->f_17fc)->g(0x444d4c42, 1);
    }
}
