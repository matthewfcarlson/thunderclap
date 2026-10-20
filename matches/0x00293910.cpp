#include "compat/ptr.h"
typedef unsigned int u32_293910;
struct CameraAnimationController {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual CameraAnimationController* f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    char pad[0x10c];
    u32_293910 field110;
    u32_293910 field114;
    void init(CameraAnimationController*);
    void finish(u32_293910);
};
extern "C" void* __cdecl alloc(hulk_uintptr);
extern u32_293910 camera_vtable_293910;
CameraAnimationController* CameraAnimationController::f4() {
    CameraAnimationController* p = (CameraAnimationController*)alloc(0x118);
    if (p) {
        p->init(this);
        *(hulk_uintptr*)p = (hulk_uintptr)&camera_vtable_293910;
        p->field110 = 0xffffffff;
        p->field114 = 0;
        p->finish(field114);
        return p;
    }
    return 0;
}