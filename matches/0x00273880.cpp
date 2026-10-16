#include "gen/core.h"

class Request_273880 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int vfunc_3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

int core::FileRequest::vfunc_3() {
    return *(int*)((char*)(*(int * *)&this->f_08) + 12);
}
