#include "gen/global.h"

class CActorManager_2e290 {
  public:
    int dummy;
    void Act(unsigned char b);
};
typedef void (CActorManager_2e290::*MFn_2e290)(unsigned char);
class Function_2e290 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};

template <> void Method1<CActorManager, void, bool>::vfunc_2(void* __p0, void* __p1, void* __p2) { CActorManager_2e290 * obj = (CActorManager_2e290 *)__p0; unsigned char * b = (unsigned char *)__p1; void * unused = (void *)__p2;

    (obj->*(*(MFn_2e290 *)&this->f_1c))(*b);
}
