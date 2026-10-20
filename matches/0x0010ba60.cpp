#include "compat/ptr.h"
extern "C" void _ReadWriteBarrier();
class Ref_10ba60 {
  public:
    virtual void A();
    virtual void B();
};
extern int vt_10ba60;
class FaceMotionAction {
  public:
    hulk_intptr vptr;
    char pad[0x18];
    int* p;
    Ref_10ba60* r;
    void Finish();
    void Run();
};
void FaceMotionAction::Run() {
    vptr = (hulk_intptr)&vt_10ba60;
    _ReadWriteBarrier();
    if (r) {
        r->B();
        r = 0;
    }
    if (p)
        p = 0;
    Finish();
}