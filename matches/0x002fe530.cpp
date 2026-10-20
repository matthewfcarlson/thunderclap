#include "compat/ptr.h"
extern "C" char DAT_004319a4[];
class SimStateHairclub {
  public:
    virtual void v0();
    virtual void v1();
    virtual SimStateHairclub* vfunc_2(unsigned char);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    void cleanup();
    char pad[0x84];
    struct Ref_2fe530* member;
};
struct Ref_2fe530 {
    virtual void a();
    virtual void b();
};
void release(SimStateHairclub*);
SimStateHairclub* SimStateHairclub::vfunc_2(unsigned char p) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_004319a4);
    Ref_2fe530* volatile* pm = &member;
    Ref_2fe530* m = *pm;
    if (m) {
        m->b();
        member = 0;
    }
    cleanup();
    if (p & 1)
        release(this);
    return this;
}
