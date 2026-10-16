#include "gen/core.h"

class Dispatch_268690 {
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
};
class Item_268690 {
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
    virtual void call(int);
};

void core::ControllerXBox::vfunc_18(int arg) {
    (*(Dispatch_268690 * *)&this->f_454)->i();
    for (unsigned int i = 0; i < this->f_14; ++i)
        ((Item_268690*)((char*)this + 0x18 + i * 0x34))->call(arg);
}
