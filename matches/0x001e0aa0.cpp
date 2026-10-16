// Same code shape as 0x0002e290 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_1e0aa0 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_1e0aa0::*MFn_1e0aa0)(unsigned char);
class Function_1e0aa0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CSPManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_1e0aa0 * obj = (CActorManager_1e0aa0 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_1e0aa0 *)&this->f_1c))(*b);
}
