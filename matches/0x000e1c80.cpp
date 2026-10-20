#include "gen/global.h"

class Base_e1c80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class Inner_e1c80 {
  public:
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
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
    virtual void ab();
    virtual void ac();
    virtual void ad();
    virtual void ae();
    virtual void af();
    virtual void ag();
    virtual void ah();
    virtual void ai();
    virtual void aj();
    virtual void ak();
};
class Container_e1c80 {
  public:
    int pad;
    Inner_e1c80* p;
};
class FEDoAction_e1c80 {
  public:
    char pad[0x10];
    Container_e1c80* m;
};

void FEDoBackMenu::vfunc_1() {
    (*(Container_e1c80 * *)&this->f_10)->p->ak();
}
