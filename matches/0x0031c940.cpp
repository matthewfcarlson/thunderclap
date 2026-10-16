#include "gen/pure3d.h"

class View_31c940 {
  public:
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void A(int);
    virtual void x7();
    virtual void B(int);
    virtual void x9();
    virtual void C(int);
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17();
    virtual void x18();
    virtual void x19();
    virtual void x20();
    virtual void x21();
    virtual void x22();
    virtual void x23();
    virtual void D(int);
    virtual void xx();
    virtual void E(int, int, int, int);
    virtual void xxx();
    virtual void F(int, int, int, int);
};

void pure3d::pddiViewState::vfunc_0(void* __p0) { void * p = (void *)__p0;

    View_31c940* v = (View_31c940*)p;
    v->A(this->f_04);
    v->B(this->f_08);
    v->C(this->f_0c);
    v->D(this->f_10);
    v->E(this->f_14, this->f_18, this->f_1c, this->f_20);
    v->F(this->f_24, this->f_28, this->f_2c, this->f_30);
}
