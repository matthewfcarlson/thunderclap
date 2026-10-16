// Same code shape as 0x0002e290 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_7d360 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_7d360::*MFn_7d360)(unsigned char);
class Function_7d360 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CAmbientsManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_7d360 * obj = (CActorManager_7d360 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_7d360 *)&this->f_1c))(*b);
}
