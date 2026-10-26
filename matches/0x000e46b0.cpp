#include "gen/global.h"
#include "decls/data/engine/pure3d/prop.h"
// data: glob_e46b0 = DAT_0052c2a0

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

void FEThingsBase::vfunc_66() {
    if (!(*(Obj_e46b0 * *)&this->f_17fc)) {
        (*(Obj_e46b0 * *)&this->f_17fc) = (*(Factory_e46b0**)&DAT_0052c2a0)->make("simple", 0);
        (*(Obj_e46b0 * *)&this->f_17fc)->a();
        (*(Obj_e46b0 * *)&this->f_17fc)->g(0x444d4c42, 1);
    }
}
