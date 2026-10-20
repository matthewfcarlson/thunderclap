#include "compat/ptr.h"
extern int vtbl_controller;
extern int vtbl_refcount;
class Sub_b36a0 {
  public:
    virtual void a();
    virtual void b();
};
class CSimController {
  public:
    virtual void f0();
    virtual void f1();
    virtual CSimController* vfunc_2(int);
    char pad[4];
    Sub_b36a0* sub;
};
extern void thunk(CSimController*);
CSimController* CSimController::vfunc_2(int flags) {
    CSimController* p = this;
    *((hulk_intptr*)p) = (hulk_intptr)&vtbl_controller;
    sub->b();
    *((hulk_intptr*)p) = (hulk_intptr)&vtbl_refcount;
    if (flags & 1)
        thunk(this);
    return this;
}