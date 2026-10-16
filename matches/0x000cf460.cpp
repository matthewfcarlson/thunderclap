// Same code shape as 0x0002e290 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_cf460 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_cf460::*MFn_cf460)(unsigned char);
class Function_cf460 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<HUDOverlay, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_cf460 * obj = (CActorManager_cf460 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_cf460 *)&this->f_1c))(*b);
}
