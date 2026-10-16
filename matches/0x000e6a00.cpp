#include "gen/global.h"

class Item_e6a00 {
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

void FEThingsBase::vfunc_32() {
    while (this->f_17f4 > 1) {
        ((Item_e6a00*)(*(void * *)&this->f_1760))->p();
        vfunc_48(1);
        --this->f_17f4;
        (*(void * *)&this->f_1760) = (*(void * (*)[16])&this->f_17b4)[this->f_17f4];
        ((Item_e6a00*)(*(void * *)&this->f_1760))->o();
    }
    vfunc_31();
}
