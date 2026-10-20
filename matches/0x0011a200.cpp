#include "compat/ptr.h"
struct RefObj_11a200 {
  public:
    virtual void v0();
    virtual void Release();
};

struct Sub60 {
  public:
    void Dtor();
};

class MotionClosestWaypointAction {
  public:
    void* mVptr;          // 0x00
    char pad1[24];        // 0x04..0x1B
    int m1c;              // 0x1C
    RefObj_11a200* volatile m20; // 0x20
    char pad2[60];        // 0x24..0x5F
    Sub60 m60;            // 0x60

    void CallBaseDtor();
    void* vfunc_2(unsigned char flag);
};

extern int dummy_vftable;
void operator delete(void*);

void* MotionClosestWaypointAction::vfunc_2(unsigned char flag) {
    *(volatile hulk_intptr*)this = (hulk_intptr)&dummy_vftable;
    RefObj_11a200* p = m20;
    if (p) {
        p->Release();
        m20 = 0;
    }
    if (m1c) {
        m1c = 0;
    }
    m60.Dtor();
    CallBaseDtor();
    if (flag & 1) {
        operator delete(this);
    }
    return this;
}
