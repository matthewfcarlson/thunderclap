// Same code shape as 0x00273880 (propagated; names are from that function)
#include "gen/core.h"

class Request_2743e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int vfunc_3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

int core::DriveRequest::vfunc_3() {
    return *(int*)((char*)(*(int * *)&this->f_08) + 12);
}
