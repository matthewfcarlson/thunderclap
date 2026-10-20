#include "gen/global.h"

class Sub_e6f60 {
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
    void helper(int);
};
class Obj_e6f60 {
  public:
    void run();
};
struct Manager_e6f60 {
    char pad[0x20];
    void* obj;
};
extern Manager_e6f60* gManager_e6f60;
extern char gByte;
extern char gFlag_e6f60;

void FEThingsBase::vfunc_23() {
    if (this->f_17b0 < 0 || (this->f_2104 == 0 && this->f_17b0 == 0)) {
        vfunc_48(7);
        return;
    }
    *(int*)((char*)this + 0x1768) = 0;
    *(int*)((char*)this + 0x17f8) = 1;
    *(int*)((char*)this + 0x176c) = 2;
    if (*(Sub_e6f60**)((char*)this + 0x175c)) {
        (*(Sub_e6f60**)((char*)this + 0x175c))->p();
        (*(Sub_e6f60**)((char*)this + 0x175c))->helper(*(int*)((char*)this + 0x176c));
    }
    vfunc_24();
    Manager_e6f60* m = gManager_e6f60;
    gByte = 1;
    if (m->obj && *(void**)((char*)m->obj + 0x124) && gFlag_e6f60) {
        gFlag_e6f60 = 0;
        ((Obj_e6f60*)*(void**)((char*)m->obj + 0x124))->run();
    }
}
