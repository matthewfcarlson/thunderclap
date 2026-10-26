#include "decls/data/engine/pure3d.h"
// data: gSentinel_327d20 = DAT_004d40d8

typedef unsigned int u32_327d20;
class Obj_327d20 {
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
    virtual int l();
    virtual void m();
    virtual void n();
    virtual void o(u32_327d20);
    void target(u32_327d20);
};
void Obj_327d20::target(u32_327d20 arg) {
    if (*(u32_327d20*)((char*)this + 12) != (*(u32_327d20*)&DAT_004d40d8)) {
        if ((*(Obj_327d20**)&DAT_005555bc))
            (*(Obj_327d20**)&DAT_005555bc)->n();
        (*(u32_327d20*)&DAT_004d40d8) = *(u32_327d20*)((char*)this + 12);
        m();
        o(arg);
        (*(Obj_327d20**)&DAT_005555bc) = this;
    } else if (l() != 1)
        o(arg);
}