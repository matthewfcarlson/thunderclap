// Same code shape as 0x0002e290 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_d70d0 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_d70d0::*MFn_d70d0)(unsigned char);
class Function_d70d0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CSimOverlayManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_d70d0 * obj = (CActorManager_d70d0 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_d70d0 *)&this->f_1c))(*b);
}
