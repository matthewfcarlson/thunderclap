#include "gen/global.h"
#include "gen/owners.h"

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
};
class B_160b0 {
  public:
    Obj_160b0* next();
};
class C_160b0 {
  public:
};
struct Data_160b0 {
    char pad[16];
    int value;
};

bool CSmartPropSetStateAction::vfunc_7(int arg) {
    Obj_160b0* a = ((Obj_160b0 *)((owners::Object_592a0 *)((*(A_160b0 * *)&this->f_1c)))->FUN_000592a0());
    B_160b0* b = (B_160b0*)a;
    a = b->next();
    C_160b0* c = (C_160b0*)a;
    Obj_160b0* p = ((Obj_160b0 *)((owners::C_35ef0 *)c)->FUN_00035ef0((hulk_intptr)0));
    if (p)
        p->h((*(Data_160b0 * *)&this->f_20)->value, 1);
    return false;
}
