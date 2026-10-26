#include "decls/data/engine/pure3d.h"
// data: g_flag_2c3230 = DAT_00554bdc, g_slot_2c3230 = DAT_00554bd8

#include "compat/ptr.h"
extern "C" char DAT_0042ed30[];
struct Caller_2c3230 {
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
    virtual void n(void* p);
};
void target(Caller_2c3230* p) {
    unsigned int one = 1;
    if ((((unsigned char)(*(unsigned int*)&DAT_00554bdc)) & one) == 0) {
        (*(unsigned int*)&DAT_00554bdc) |= one;
        (*(unsigned int*)&DAT_00554bd8) = ((hulk_intptr)DAT_0042ed30);
    }
    p->n((void*)&(*(unsigned int*)&DAT_00554bd8));
}
