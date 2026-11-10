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
extern "C" void FUN_002c3230(Caller_2c3230* p) {
    unsigned int one = 1;
    if ((((unsigned char)(*(unsigned int*)&DAT_00554bdc)) & one) == 0) {
        (*(unsigned int*)&DAT_00554bdc) |= one;
        (*(void**)&DAT_00554bd8) = (void*)DAT_0042ed30;  // a pointer slot (config/data-ptrs.json): 8 bytes on 64-bit
    }
    p->n((void*)&(*(unsigned int*)&DAT_00554bd8));
}
