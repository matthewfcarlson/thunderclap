// Same code shape as 0x0002e290 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_9b310 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_9b310::*MFn_9b310)(unsigned char);
class Function_9b310 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CCameraManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_9b310 * obj = (CActorManager_9b310 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_9b310 *)&this->f_1c))(*b);
}
