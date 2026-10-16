#include "gen/global.h"

class Obj_160b0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual int h(int, int);
};
class A_160b0 {
  public:
    Obj_160b0* get();
};
class B_160b0 {
  public:
    Obj_160b0* next();
};
class C_160b0 {
  public:
    Obj_160b0* find(int);
};
struct Data_160b0 {
    char pad[16];
    int value;
};

bool CSmartPropSetStateAction::vfunc_7(int arg) {
    Obj_160b0* a = (*(A_160b0 * *)&this->f_1c)->get();
    B_160b0* b = (B_160b0*)a;
    a = b->next();
    C_160b0* c = (C_160b0*)a;
    Obj_160b0* p = c->find(0);
    if (p)
        p->h((*(Data_160b0 * *)&this->f_20)->value, 1);
    return false;
}
