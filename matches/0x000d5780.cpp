// Same code shape as 0x0002e290 (propagated; names are from that function)
#include "gen/global.h"

class CActorManager_d5780 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_d5780::*MFn_d5780)(unsigned char);
class Function_d5780 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<MessageOverlay, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_d5780 * obj = (CActorManager_d5780 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_d5780 *)&this->f_1c))(*b);
}
