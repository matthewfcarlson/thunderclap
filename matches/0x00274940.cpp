#include "gen/core.h"

class Service_274940 {
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
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u(void*);
};
class Inner_274940 {
  public:
    virtual void close();
    virtual void done();
};
struct Drive_274940 {
    virtual void v0();
    char pad[8];
    Service_274940* service;
    char pad2[0x10];
    unsigned char flag;
};

int core::DriveFindCloseRequest::vfunc_1() {
    Drive_274940* d = (*(Drive_274940 *volatile *)&this->f_08);
    Service_274940* s = d->service;
    d->flag = 0;
    s->u((char*)(*(Drive_274940 *volatile *)&this->f_08) + 0x1c);
    ((Inner_274940*)((char*)(*(Drive_274940 *volatile *)&this->f_08) + 4))->close();
    *(int*)((char*)(*(Drive_274940 *volatile *)&this->f_08) + 0x18) = 0;
    ((Inner_274940*)((char*)(*(Drive_274940 *volatile *)&this->f_08) + 4))->done();
    return 1;
}
