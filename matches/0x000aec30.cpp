// Same code shape as 0x0002e290 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_aec30 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_aec30::*MFn_aec30)(unsigned char);
class Function_aec30 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CControllerManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_aec30 * obj = (CActorManager_aec30 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_aec30 *)&this->f_1c))(*b);
}
