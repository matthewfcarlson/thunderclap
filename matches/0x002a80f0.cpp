#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
extern int vt1_2a80f0;
extern void Free(void*);
class SimpleFrameController_2a80f0 {
  public:
    void* vptr;
    ~SimpleFrameController_2a80f0() throw();
};
class CompDrawVisibilityAnimationController_2a80f0 : public SimpleFrameController_2a80f0 {
  public:
    char p[0x3c];
    int a40;
    hulk_intptr a44;
    char q[8];
    void* a50;
    ~CompDrawVisibilityAnimationController_2a80f0() throw();
};
CompDrawVisibilityAnimationController_2a80f0::~CompDrawVisibilityAnimationController_2a80f0() throw() {
    vptr = &vt1_2a80f0;
    a40 = 0;
    _ReadWriteBarrier();
    if (a50)
        Free(a50);
    if (a44)
        Free((void*)a44);
}
