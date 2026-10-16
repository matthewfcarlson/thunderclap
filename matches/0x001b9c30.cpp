// Same code shape as 0x0002e290 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1b9c30 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_1b9c30::*MFn_1b9c30)(unsigned char);
class Function_1b9c30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CRenderManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1b9c30 * obj = (CActorManager_1b9c30 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_1b9c30 *)&this->f_1c))(*b);
}
