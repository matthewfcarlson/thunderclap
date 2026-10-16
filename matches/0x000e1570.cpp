#include "gen/global.h"

class FEThing_e1570 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12(void*);
};
class FEData {
  public:
    char pad[0x4c];
    FEThing_e1570* obj;
};

void FEPoseAnimation::vfunc_4(int __p0) { void * arg = (void *)__p0;

    FEThing_e1570* p = (*(FEData * *)&this->f_0c)->obj;
    if (p)
        p->a12(arg);
}
