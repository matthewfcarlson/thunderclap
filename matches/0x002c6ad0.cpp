#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042ef74[];
class Ref_2c6ad0 {
  public:
    virtual void F0();
    virtual void Release();
};
class DisplayTraversal {
  public:
    volatile int vf;
    int p0, p1, p2, p3;
    Ref_2c6ad0* volatile mRef;
    DisplayTraversal* F2(unsigned int);
};
extern void Destroy(DisplayTraversal*);
DisplayTraversal* DisplayTraversal::F2(unsigned int flags) {
    vf = ((hulk_intptr)DAT_0042ef74);
    Ref_2c6ad0* r = mRef;
    if (r) {
        r->Release();
        mRef = 0;
    }
    vf = ((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        Destroy(this);
    return this;
}