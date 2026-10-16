#include "gen/pure3d.h"

class pddiObject_3271f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
class pddiPrimBuffer_3271f0 : public pddiObject_3271f0 {
  public:
    virtual void v6();
};

void pure3d::d3dPrimBuffer::vfunc_5(void* __p0) { void * p = (void *)__p0;

    *(char*)((char*)this + 0x34) = 0;
    *(char*)((char*)p + 4) = 0;
}
